# keras를 이용한 ANN 예제 : Fashion_MNIST 데이터 분석
# tensorflow 1.15버전 이용
# 데이터 전처리는 되어있는 것으로 이용

# 1. 데이터 설정
import matplotlib.pyplot as plt
import tensorflow as tf
from tensorflow import keras # keras는 코드를 직관적으로, 모델을 좀 더 다양하게 활용할 수 있게 만들어주는 패키지
import numpy as np

print(tf.__version__)

fashion_mnist = keras.datasets.fashion_mnist
(train_images, train_labels), (test_images, test_labels) = fashion_mnist.load_data()

class_names = ['T-shirt/top', 'Trouser', 'Pullover', 'Dress', 'Coat', 'Sandal', 'Shirt', 'Sneaker', 'Bag', 'Ankle boot']

print('====== train =======')
print(train_images.shape)
print(len(train_labels))
print(train_labels)

print('======= test =======')
print(test_images.shape)
print(test_labels)

# 입력 데이터 확인
plt.figure()
plt.imshow(train_images[0])
plt.colorbar()
plt.grid(False)
plt.show()

# 데이터 정규화. 이미지 데이터이므로 255 이용
train_images = train_images / 255.0

test_images = test_images / 255.0

# 정규화된 데이터 확인
plt.figure(figsize=(10,10))
for i in range(25):
  plt.subplot(5,5,i+1)
  plt.xticks([])
  plt.yticks([])
  plt.grid(False)
  plt.imshow(train_images[i], cmap=plt.cm.binary)
  plt.xlabel(class_names[train_labels[i]])
plt.show()

# 2-1. 모델 생성 1
model = keras.Sequential([
                          keras.layers.Flatten(input_shape=(28, 28)),
                          keras.layers.Dense(128, activation='relu'),
                          keras.layers.Dense(10, activation='softmax')])


# 2-2. 모델 생성 2
# model = keras.Sequential()[
# model.add([
#            keras.layers.Flatten(input_shape=(28, 28)),
#            keras.layers.Dense(128, activation='relu'),
#            keras.layers.Dense(10, activation='softmax')])


# 3. 모델 학습
model.compile(optimizer='adam', 
              loss='sparse_categorical_crossentropy', 
              metrics=['accuracy'])

model.fit(train_images, train_labels, epochs=5)




# 4. 성능 측정

test_loss, test_acc = model.evaluate(test_images, test_labels, verbose=2)
# verbose : 일정 정확도에 도달하면 정확도가 높아지지 않고 떨어지는 경우가 있음. 이 때 몇번 째에 그걸 stop할 거냐를 설정

print('\n테스트 정확도:', test_acc)

# Sequential model을 만들어서 모델에 Softmax만 넣은다음 test 이미지를 넣었을 때의 성능 확인
probability_model = tf.keras.Sequential([model, tf.keras.layers.Softmax()])
# 모델에 새로 테스트 데이터를 넣었을 때 값이 어떻게 출력이 되는지 보기 위함.

predictions = probability_model.predict(test_images)

print(predictions[0])

print(np.argmax(predictions[0]))

print(test_labels[0])

def plot_image(i, predictions_array, true_label, img):
  true_label, img = true_label[i], img[i]
  plt.grid(False)
  plt.xticks([])
  plt.yticks([])

  plt.imshow(img, cmap=plt.cm.binary)

  predicted_label = np.argmax(predictions_array)
  if predicted_label == true_label:
    color = 'blue'
  else:
    color = 'red'

  plt.xlabel("{} {:2.0f}% ({})".format(class_names[predicted_label],
                                100*np.max(predictions_array),
                                class_names[true_label]),
                                color=color)

def plot_value_array(i, predictions_array, true_label):
  true_label = true_label[i]
  plt.grid(False)
  plt.xticks(range(10))
  plt.yticks([])
  thisplot = plt.bar(range(10), predictions_array, color="#777777")
  plt.ylim([0, 1])
  predicted_label = np.argmax(predictions_array)

  thisplot[predicted_label].set_color('red')
  thisplot[true_label].set_color('blue')

i = 0
plt.figure(figsize=(6,3))
plt.subplot(1,2,1)
plot_image(i, predictions[i], test_labels, test_images)
plt.subplot(1,2,2)
plot_value_array(i, predictions[i],  test_labels)
plt.show()

i = 12
plt.figure(figsize=(6,3))
plt.subplot(1,2,1)
plot_image(i, predictions[i], test_labels, test_images)
plt.subplot(1,2,2)
plot_value_array(i, predictions[i],  test_labels)
plt.show()

# Plot the first X test images, their predicted labels, and the true labels.
# Color correct predictions in blue and incorrect predictions in red.
num_rows = 5
num_cols = 3
num_images = num_rows*num_cols
plt.figure(figsize=(2*2*num_cols, 2*num_rows))
for i in range(num_images):
  plt.subplot(num_rows, 2*num_cols, 2*i+1)
  plot_image(i, predictions[i], test_labels, test_images)
  plt.subplot(num_rows, 2*num_cols, 2*i+2)
  plot_value_array(i, predictions[i], test_labels)
plt.tight_layout()
plt.show()




