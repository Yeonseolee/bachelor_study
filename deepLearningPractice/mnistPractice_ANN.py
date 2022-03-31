# ANN(artificial neural network)을 이용한 MNIST 데이터 분석_tensorflow를 이용해서


# 1. 데이터 세팅

import matplotlib.pyplot as plt
import tensorflow as tf
import numpy as np

train, test = tf.keras.datasets.mnist.load_data()
train_x, train_y = train
test_x, test_y = test

print(train_y)

# eye 함수 : 대각행렬을 만들어주는. identify함수 - n x n 대각행렬 생성. eye 함수 - n x m 대각행렬 가능
x = np.eye(3)[[1,2,0]]
y = np.eye(3)
print(x)
print(y)

# shape 함수 사용
print(train_y)
print(train_y.shape)  # --> 단차원 행열
y_vals_train = np.eye(10)[train_y] # 여기서 10은 클래스의 개수
y_vals_test = np.eye(10)[test_y]

print(y_vals_train.shape) # --> 10개의 클래스를 가진 2차원 행열. 단차원으로 y값 사용시 색?이 안맞아서 변형
print(y_vals_train)

# shape 함수 : 행렬의 차원을 shape라는 개념으로 표현. 예를 들어, [[1,2,3,4],[1,2,3,4]] 1차원에 4, 2차원에 2로 (4,2)로 표현. x, y, z 순이라 보면 됌. 
print("train_x's shape ", train_x.shape)
print("train_x's shape[0] ", train_x.shape[0])
print("train_x's shape[1] ",train_x.shape[1])
print("train_x's shape[2] ", train_x.shape[2])


# 2차원 -> 2차원과 3차원의 곱으로 변경. 일반 뉴럴 네트워크는 input Data를 2차원 행렬을 1차원 행렬로 바꿔줌
x_vals_train = train_x.reshape(train_x.shape[0],train_x.shape[1]*train_x.shape[2]) # train_x는 3차원. reshape 함수를 통해 2차원으로 변경
x_vals_test = test_x.reshape(test_x.shape[0], test_x.shape[1]*test_x.shape[2])
print(x_vals_train.shape)


# Normalization 실행. 이미지 데이터는 0 ~ 255까지로 표현됨. 이걸 255로 나누면 모든 값이 0 ~ 1 사이의 값으로 변환됨. 
x_vals_train = x_vals_train/255. # numpy array 전체 값에 대한 연산. 전체 값 나누기
x_vals_test = x_vals_test/255. 



# 2. 모델 생성


# 이미지 분석 시 CNN이 뉴럴네트워크보다 정확도가 더 높은 이유: 2차원을 그대로 분석하기 때문. 여기서는 2차원을 1차원으로 변환(28*28)
x_data = tf.placeholder(shape=[None, 784], dtype=tf.float32)
y_target = tf.placeholder(shape=[None, 10], dtype=tf.float32) # 여기서 10은 클래스의 개수

hidden_layer_nodes_1 = 100
hidden_layer_nodes_2 = 50
hidden_layer_nodes_3 = 10

W1 = tf.Variable(tf.random_normal(shape=[784, hidden_layer_nodes_1]))
b1 = tf.Variable(tf.random_normal(shape=[hidden_layer_nodes_1]))

W2 = tf.Variable(tf.random_normal(shape=[hidden_layer_nodes_1, hidden_layer_nodes_2]))
b2 = tf.Variable(tf.random_normal(shape=[hidden_layer_nodes_2]))

W3 = tf.Variable(tf.random_normal(shape=[hidden_layer_nodes_2, hidden_layer_nodes_3]))
b3 = tf.Variable(tf.random_normal(shape=[hidden_layer_nodes_3]))


hidden_out_1 = tf.nn.relu(tf.add(tf.matmul(x_data, W1), b1))

hidden_out_2 = tf.nn.relu(tf.add(tf.matmul(hidden_out_1, W2), b2))  # A[1] = h(W2 * (hidden_out_1) + b2)

final_output = tf.nn.softmax(tf.add(tf.matmul(hidden_out_2, W3), b3))

prediction = tf.argmax(final_output, 1)
# argmax : 
correct_prediction = tf.equal(prediction, tf.argmax(y_target, 1))
accuracy = tf.reduce_mean(tf.cast(correct_prediction, tf.float32))


# Minimize error using cross entropy
loss = tf.reduce_mean(tf.nn.softmax_cross_entropy_with_logits(logits=final_output, labels=y_target)) # softmax loss

# Gradient Descent
train_step = tf.train.AdamOptimizer(learning_rate=0.01).minimize(loss)
# train_step = tf.train.GradientDescentOptimizer(learning_rate=1).minimize(loss)

sess = tf.Session()
seed = 500  # 다시 돌려도 똑같은 값들을 얻고 싶을 때 사용. 이걸 사용하지 않으면 초기화 시킬 때의 랜덤값들이 바뀜
tf.set_random_seed(seed)

# 초기 가중치 선언 및 초기값 세션 실행
init = tf.global_variables_initializer()

sess.run(init)



# 4. 모델 학습


loss_vec = []
test_loss = []
train_acc = []
test_acc = []

batch_size = 10000

for i in range(1000):
  rand_index = np.random.choice(len(x_vals_train), size= batch_size)
  rand_x = x_vals_train[rand_index]
  rand_y = y_vals_train[rand_index]

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
