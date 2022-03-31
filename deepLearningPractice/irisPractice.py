# tensorflow를 이용한 아이리스 실습

# !pip uninstall tensorflow
# !pip install tensorflow==1.15

import matplotlib.pyplot as plt
import tensorflow as tf
import numpy as np
import pandas as pd
from sklearn import datasets




# 1. 데이터 세팅


df_iris = pd.read_csv("http://archive.ics.uci.edu/ml/machine-learning-databases/iris/iris.data", header=None)

df_iris.columns = ['sepal length in cm', 'sepal width in cm', 'petal length in cm', 'petal width in cm', 'class']
df_iris['class'] = df_iris['class'].map({"Iris-setosa":0, "Iris-versicolor":1, "Iris-virginica":2})

X = df_iris.iloc[:, 0:3]
y = df_iris.iloc[:, 4]

print('The X is \n',  X, '\n')
print('The Y is \n', y, '\n')

x_vals = np.array(X)
y_vals = np.array(y)

print('The x_vals is \n', x_vals,'\n')
print('The y_vals is \n', y_vals,'\n')

df_iris.head()




# 2. Random seed 설정 및 정규화

seed = 500 

sess = tf.Session()
tf.set_random_seed(seed)
np.random.seed(seed)

# index 랜덤으로 뽑아내기
train_indices = np.random.choice(len(x_vals), round(len(x_vals)*0.8), replace=False)
print(train_indices, '\n', len(train_indices), '\n')
test_indices = np.array(list(set(range(len(x_vals)))-set(train_indices)))
print(test_indices, '\n', len(test_indices), '\n')

# 랜덤 index를 각 train, test 데이터셋에 맞게 보관
x_vals_train = x_vals[train_indices]
x_vals_test = x_vals[test_indices]

y_vals_train = y_vals[train_indices]
y_vals_test = y_vals[test_indices]

print("x_vals_train is \n", x_vals_train,'\n')
print("y_vals_train is \n", y_vals_train,'\n')

#  데이터 정규화(Normalization) 함수 정의 - 정규화 데이터: column(x값)
def normalize_cols(m):
  col_max = m.max(axis=0)
  col_min = m.min(axis=0)
  return (m-col_min) / (col_max - col_min)

# 데이터 정규화
x_vals_train = np.nan_to_num(normalize_cols(x_vals_train))
x_vals_test = np.nan_to_num(normalize_cols(x_vals_test))




# 3. 인공신경망 모델 생성


batch_size = 50     # 학습 시 데이터를 얼마나 보고 학습할건지. 50개씩 끊어서 본다는 의미 
# 사용량과 값이 비례하는게 정확도에 좋음. 높을수록 정확도가 높아짐

# ====== 변수 설정 =========

# tensorflow 버전 1에서는 데이터를 담을 그릇을 먼저 선언해야 함 -> placeholder(), 데이터 사이즈에 맞춰 정의
# None 부분은 훈련시킬 데이터 개수(변화되는 데이터 개수). 몇 개인지 굳이 정의할 필요 없음. / 3은 받을 변수 = 클래스 개수와 동일
x_data = tf.placeholder(shape=[None, 3], dtype=tf.float32)   # x(입력값)의 클래스 3개
y_target = tf.placeholder(shape=[None], dtype=tf.float32) # y(타겟값 혹은 예측값)의 클래스 1개

# 히든 레이어의 노드 개수. 노드의 개수에 따라 종류 및 성능이 달라짐. 
hidden_layer_nodes = 5

# 현재 레이어 노드의 개수 * 다음 레이어 노드의 개수 = 가중치 개수
W1 = tf.Variable(tf.random_normal(shape=[3, hidden_layer_nodes]))  # 가중치 개수 = 3 * 5
b1 = tf.Variable(tf.random_normal(shape=[hidden_layer_nodes]))

W2 = tf.Variable(tf.random_normal(shape=[hidden_layer_nodes, 1])) # 가중치 개수 = 5 * 1
b2 = tf.Variable(tf.random_normal(shape=[1]))

# ========== 계산 ===========

# matmul() : 행렬의 곱 계산하는 함수
hidden_out = tf.nn.relu(tf.add(tf.matmul(x_data, W1), b1))  # A[0] = h( W1 * X + b) / 이 식에서 h()는 relu 함수

final_output = tf.nn.relu(tf.add(tf.matmul(hidden_out, W2), b2))  # A[1] = h(W2 * hidden_out + b)

prediction = tf.round(final_output) # round() : 반올림 함수

# prediction(학습한 y값)과 실제 y값(타겟값)이 일치한지를 보는
prediction_correct = tf.cast(tf.equal(prediction, y_target), tf.float32)

# 일치한 정도 평균내기. 계산법을 여기서는 이렇게 사용해도 되서 간략화.  
# 더 정확하게 하려면 그 기계학습이랑 의료 때 배웠던 식 사용하면 됨
accuracy = tf.reduce_mean(prediction_correct)


# 경사하강법을 사용하기 위해 에러가 낮은지 아닌지 판단하기 위한 지표(기준) -> 경사하강법에서 미분 최소값(기계학습 참고)
loss = tf.reduce_mean(tf.square(y_target-final_output)) # (실제 값 - 예측한 값)^2 -> 기계학습 자료보면 더 이해될듯


# 경사하강법으로 최적화. / 0.001은 가중치를 얼만큼 업데이트할 것인지에 대한 정도를 나타내는 상수 -> 기계학습 참고
my_opt = tf.train.GradientDescentOptimizer(0.001)  # 최적화(optimization) 함수 중 하나. 여러가지가 존재
train_step = my_opt.minimize(loss) # loss가 작아지는 방향(minimize)으로 my_opt 변수를 최적화(바로 위의 함수)하겠다. -> loss 변수보다 값이 더 작을 수 밖에 없음

# 0으로 시작하면 오버피팅 등 최적화가 잘 안되는 문제가 발생. 
# session 시작 시 초기값 설정. 슬라이드 9페이지 참고. 
init = tf.global_variables_initializer() # 초기값 설정하는 optimizer 함수도 여러가지가 존재. 
sess.run(init)



# 4. 모델 학습

loss_vec = [] # 전체 loss 값들을 담는 변수 / 앞에서 설정한 loss값들을 저장하기 위한 리스트. loss는 vetor로 구성되므로 이름에 vec이 붙음. 
test_loss = [] # test 단계에서의 loss를 담을 수 있는 변수
train_acc = [] # train 단계의 정확도를 담는 변수
test_acc = []  # test 단계의 정확도를 담는 변수

for i in range(10000):
  #  인덱스를 랜덤하게 해서 x, y리스트에 집어넣기
  rand_index = np.random.choice(len(x_vals_train), size= batch_size) 
  # 위에 y 그릇 생성시(placeholder 부분) shape=[None, 1]로 주게 되면 오류 생김. 프로그램에 따라 다름. 
  # 만약 y의 클래스가 여러개면 어떤 부분을 어떻게 바꿔야 되나..
  rand_x = x_vals_train[rand_index]
  rand_y = y_vals_train[rand_index]

  # feed_dic : x변수와 y변수를 diction하게 넣어주겠다. train_step(loss 보다 더 작은 loss)를 고려하여 secssion을 실행하겠다. 
  sess.run(train_step, feed_dict={x_data: rand_x, y_target: rand_y}) 
  
  temp_loss = sess.run(loss, feed_dict={x_data: rand_x, y_target: rand_y})
  loss_vec.append(np.square(temp_loss))

  test_temp_loss = sess.run(loss, feed_dict={x_data: x_vals_test, y_target: y_vals_test})
  test_loss.append(np.square(test_temp_loss))

  acc_temp_train = sess.run(accuracy, feed_dict={x_data: rand_x, y_target: rand_y})
  train_acc.append(acc_temp_train)

  acc_temp_test = sess.run(accuracy, feed_dict={x_data: x_vals_test, y_target: y_vals_test})
  test_acc.append(acc_temp_test)

  if (i+1)%50 ==0:
    print('Generation: '+ str(i+1) + '.Loss=' + str(temp_loss))
    print('Accuracy:', acc_temp_train)
    print('Average Accurcy:', np.mean(np.array(train_acc)))




# 5. 성능 측정
plt.figure(figsize=(10,10))

plt.subplot(2, 1, 1)
plt.plot(loss_vec, 'k-', label='Train Loss')
plt.plot(test_loss, 'r--', label='Test Loss')
plt.title('Loss (MSE) per Generation')
plt.legend(loc='upper right')
plt.xlabel('Generation')
plt.ylabel('Loss')

plt.subplot(2, 1, 2)
plt.plot(train_acc, 'k-', label='Train Acc')
plt.plot(test_acc, 'r--', label='Test Acc')
plt.title('Train and Test Accuracy')
plt.legend(loc='lower right')
plt.xlabel('Generation')
plt.ylabel('Accuracy')

plt.show()

