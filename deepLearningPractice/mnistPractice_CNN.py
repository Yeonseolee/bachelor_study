# CNN을 이용한 MNIST 데이터 분석_tensorflow를 이용해서

# 밑에 부분 외에 ANN과 동일
# 모델 학습의 차이

batch_size = 10000

x_data = tf.placeholder(shape=[None, 784], dtype=tf.float32)
X_img = tf.reshape(x_data, [-1, 28, 28, 1])  
# -1 : 위의 None과 동일한 역할. 변화되는 데이터를 받기 위한 부분
# 784 => 28*28(가로*세로) / 1 => 채널. RGB로 3채널이었던 것을 흑백의 단차원으로 변경
# X_img : CNN의 input값. / X_img와 동일한 형태의 가중치를 만들어줘야함. => W1 4차원. but 차원별 의미가 조금 다름
y_target = tf.placeholder(shape=[None, 10], dtype=tf.float32)

# W1,W2,W3 : convolution layer 필터 사이즈를 의미
W1 = tf.Variable(tf.random_normal(shape=[3, 3, 1, 32], stddev = 0.01))
# 3*3 : filter size / 1 : 채널 개수. X_img의 채널 값이 1이라 1 / 32 : 필터의 개수. 두번째 레이어 돌릴 때의 채널 수가 됨. / stddev : 표준편차

L1 = tf.nn.conv2d(X_img, W1, strides=[1, 1, 1, 1], padding = 'SAME')
# tf.nn.conv2d: 텐서플로우에 내장된 convolution layer생성 함수 
# strides : 필터가 움직이는 이동값. 맨 앞뒤는 보통 1로 고정. 중간 두 값은 보통 같은 값을 사용. 중간 두 값은 필터가 움직이는 칸 수를 의미
# padding='SAME' : zero padding 생성해주는 부분. input size와 output size를 동일하게 만들 수 있도록. pdf pg. 7 참고
L1 = tf.nn.relu(L1)

L1 = tf.nn.max_pool(L1, ksize = [1, 2, 2, 1], strides=[1, 2, 2, 1], padding='SAME')
# max_pool : 사이즈를 줄이는 역할. 계산법 : pg.8 참고. 
# kernal= : max_pooling layer 필터 사이즈. size = 2 *2 로 설정한 것. ksize의 맨 앞뒤는 1로 고정. filter size가 2*2 이므로 28*28 사이즈가 2배 감소 => 14*14
# strides가 2, 2 이므로 2칸씩 이동한다 보면 됨.


W2 = tf.Variable(tf.random_normal(shape=[3, 3, 32, 64], stddev = 0.01))
# 3 * 3 : 필터 사이즈 / 32 : 채널 개수. 첫 레이어의 필터 개수가 32개라 / 64 : 필터 개수 
L2 = tf.nn.conv2d(L1, W2, strides=[1, 1, 1, 1], padding = 'SAME')
L2 = tf.nn.relu(L2)
L2 = tf.nn.max_pool(L2, ksize = [1, 2, 2, 1], strides=[1, 2, 2, 1], padding='SAME')
L2_flat = tf.reshape(L2, [ -1, 7*7*64])
# 4차원에서 2차원으로 변경. pg. 4, 9 참고. flat하게 만들어줌. 

hidden_layer_nodes_2 = 7*7*64
hidden_layer_nodes_4 = 10

W3 = tf.Variable(tf.random_normal(shape=[hidden_layer_nodes_2, hidden_layer_nodes_3]))
b3 = tf.Variable(tf.random_normal(shape=[hidden_layer_nodes_3]))

final_output = tf.nn.relu(tf.add(tf.matmul(L2_flat, W3), b3))