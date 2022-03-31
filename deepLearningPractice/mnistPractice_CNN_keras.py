
# keras를 이용한 ANN 예제 : Fashion_MNIST 데이터 분석
# categorical crossentropy를 사용한 버전. 따라서 onehot encoding 된 결과로 나오기 위해 MNIST 했을 때처럼 y값을 대각행렬로 변경해주는 과정이 필요
# 전처리된 데이터 이용




# 1. 데이터 입력

# TensorFlow and tf.keras
import tensorflow as tf

# Helper libraries
import numpy as np
import matplotlib.pyplot as plt

print(tf.__version__)

class_names = ['T-shirt/top', 'Trouser', 'Pullover', 'Dress', 'Coat',
               'Sandal', 'Shirt', 'Sneaker', 'Bag', 'Ankle boot']
print(train_images.shape)
train_image = train_images.reshape(train_images.shape[0], train_images.shape[1], train_images.shape[2], 1)
# 기존의 3차원을 4차원으로 변경 CNN사용하기 위해서. RGB 데이터를 일반적으로 쓰기 때문에 1로 만듬. 
# => 나중에 실제 동영상 데이터는 RGB(3 채널)을 1로 변환해주는 작업이 필요.
print(train_image.shape)
print(len(train_labels))
print(train_labels)


# to_categorical 함수를 사용해서 y값 차원 변경시켜줄 것.
def to_categorical(y, num_classes=None, dtype='float32'):
    y = np.array(y, dtype='int')
    input_shape = y.shape
    if input_shape and input_shape[-1] == 1 and len(input_shape) > 1:
        input_shape = tuple(input_shape[:-1])
    y = y.ravel()
    if not num_classes:
        num_classes = np.max(y) + 1
    n = y.shape[0]
    categorical = np.zeros((n, num_classes), dtype=dtype)
    categorical[np.arange(n), y] = 1
    output_shape = input_shape + (num_classes,)
    categorical = np.reshape(categorical, output_shape)
    return categorical

print(train_labels.shape)
print(test_labels.shape)

num_classes = 10 # y의 출력 클래스 개수
train_label = to_categorical(train_labels, num_classes)
test_label = to_categorical(test_labels, num_classes)

print(train_label.shape)
print(test_label.shape)

train_image = train_image / 255.0
test_image = test_image / 255.0

# 모델에 input할 데이터의 형태를 결정해주는 코드
Input_shape = train_image.shape[1:]
# 위에 보면 (60000, 28, 28, 1)인데 60000은 데이터의 개수 -> 모양을 나타내는 것이 아니므로 제함. 
print(Input_shape)


# 2-1. 모델 설계 1: 주석을 다 제거하면 성능은 좋지만 시간을 많이 잡아먹음

# import tensorflow.keras as keras
# from tensorflow.keras.models import Sequential
# from tensorflow.keras.layers import Dense, Flatten
# from tensorflow.keras.layers import Conv2D, MaxPooling2D

# model = Sequential()
# # model.add(Conv2D(96, kernel_size=(11, 11), padding='same', strides=(4, 4), activation='relu', input_shape=Input_shape))
# # model.add(MaxPooling2D(pool_size=(3, 3), strides=(2, 2)))

# # model.add(Conv2D(256, kernel_size=(5, 5), padding='same', activation='relu', input_shape=Input_shape))
# # model.add(MaxPooling2D(pool_size=(3, 3), strides=(2, 2)))

# model.add(Conv2D(32, kernel_size=(3, 3), padding ='same', activation='relu', input_shape=Input_shape))
# # model.add(Conv2D(348, kernel_size=(3, 3), padding='same', activation='relu'))

# # model.add(Conv2D(256, kernel_size=(3, 3), padding='same', activation='relu'))
# model.add(MaxPooling2D(pool_size=(2, 2), strides=(2, 2)))

# model.add(Flatten())
# # model.add(Dense(500, activation='relu'))
# model.add(Dense(50, activation='relu'))
# model.add(Dense(num_classes, activation='softmax'))



# 2-2. 모델설계 2 : 위의 코드와 비교해볼 것 ==============

import tensorflow.keras as keras
from tensorflow.keras.models import Sequential
from tensorflow.keras.layers import Dense, Flatten
from tensorflow.keras.layers import Conv2D, MaxPooling2D


model = Sequential()
model.add(Conv2D(32, kernel_size=(3, 3), padding ='same', activation='relu', input_shape=Input_shape))
model.add(MaxPooling2D(pool_size=(2, 2), strides=(2, 2)))

model.add(Flatten())  # 차원을 1차원으로 바꿔주는 코드와 대응
model.add(Dense(50, activation='relu')) # Dense : free connected layer의 뉴런 개수

model.add(Dense(num_classes, activation='softmax'))
# num_classes 부분 : 뉴런을 몇개로 구분해서 출령할 것인지를 설정하는 부분. 

# ===================

model.compile(loss=keras.losses.categorical_crossentropy, 
              optimizer=keras.optimizers.Adam(lr=0.01), 
              metrics = ['accuracy'])

print(model.summary()) # 모델이 어떻게 구성되어있는지를 보여줌. 

batch_size = 128
epochs = 20

history = model.fit(train_image, train_label, batch_size=batch_size, epochs=epochs,
                            validation_split=0.2, shuffle=True)
# validation_split : 학습할 때 제대로 학습하는지 검증할 필요가 있음. 검증할 데이터를 train 데이터에서 20퍼센트 빼내서 실행, 80퍼센트만 학습
# suffle : 데이터를 섞는 것. 좀 더 정확도를 높이기 위해서


# 3. 성능 측정
print(history.history.keys())


# summarize history for accuracy
plt.plot(history.history['accuracy']) # train_accuracy임. 이 때 키워드 바꾸면 실행안되서 걍 accuracy로
plt.plot(history.history['val_accuracy']) # validation accuracy임.
plt.title('model accuracy')
plt.ylabel('accuracy')
plt.xlabel('epoch')
plt.legend(['train', 'val'], loc='upper left')
plt.show()


# summarize history for loss
plt.plot(history.history['loss'])
plt.plot(history.history['val_loss'])
plt.title('model loss')
plt.ylabel('loss')
plt.xlabel('epoch')
plt.legend(['train', 'val'], loc='upper left')
plt.show()

test_loss, test_acc = model.evaluate(test_image,  test_label, verbose=2)

print('\nTest accuracy:', test_acc)

probability_model = tf.keras.Sequential([model, 
                                         tf.keras.layers.Softmax()])

predictions = probability_model.predict(test_image)
print(predictions[0])

print(np.argmax(predictions[0]))
print(test_labels[0])


# 이미지로 출력
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


