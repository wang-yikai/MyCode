from keras.datasets import mnist
import matplotlib.pyplot as plt
from collections import Counter
import numpy as np

(x_train, y_train), (x_test, y_test) = mnist.load_data()

def least_common_digit(x_set, y_set):
    '''
       Input: x_set, the x values of the dataset and y_set, the y values of the  dataset
       Expected Output: The image from the x set of the least common digit.
    '''
    least_common = Counter(y_set).most_common()[-1][0]
    for i,num in enumerate(y_set):
        if num == least_common:
            return x_set[i]

def most_common_digit(x_set, y_set):
    '''
       Input: x_set, the x values of the dataset and y_set, the y values of the  dataset
       Expected Output: The image from the x set of the most common digit.
    '''
    most_common = Counter(y_set).most_common()[0][0]
    for i,num in enumerate(y_set):
        if num == most_common:
            return x_set[i]

def plot_two(im1, title1, im2, title2):
    '''
        Input: im1, a matrix representing a grayscale image and title1 a string,im2 a matrix representing
        a grayscale image and title2 a string
        Expected Output: A tuple (fig, ax) representing a generated figure from matplotlib and two subplots
        ready to display the inputed images with the given titles
    '''
    fig, ax = plt.subplots(1,2)
    ax[0].imshow(im1, cmap='gray')
    ax[0].set_title(title1)
    ax[1].imshow(im2, cmap='gray')
    ax[1].set_title(title2)
    return (fig, ax)

def how_many_of_each_digit(y_set):
    vals_by_count = {}
    for i in y_set:
        if i in vals_by_count:
            vals_by_count[i] += 1
        else:
            vals_by_count[i] = 1
    return vals_by_count

def bar_chart(train, test):
    ind = np.arange(len(test))
    width = 0.4

    p1 = plt.bar(ind, test.values(), width, color='#FF0000')
    p2 = plt.bar(ind, train.values(), width, bottom=list(test.values()))

    plt.xticks(ind)
    plt.yticks(np.arange(0, 10000, 1000))

    fig, ax = plt.subplots()
    plt.close(2)

    return (fig, ax)

# print(x_train)
# print(y_train)
# print(x_test)
# print(y_test)

lc_train = least_common_digit(x_train, y_train)
lc_test = least_common_digit(x_test, y_test)

mc_train = most_common_digit(x_train, y_train)
mc_test = most_common_digit(x_test, y_test)

# print(lc_train)
# print(lc_test)
# print(mc_train)
# print(mc_test)

plot_two(lc_train, 'Least Common Train', lc_test, 'Least Common Test'), plot_two(mc_train, 'Most Common Train', mc_test, 'Most Common Test')
plt.show()

count_train = how_many_of_each_digit(y_train)
count_test = how_many_of_each_digit(y_test)

# print(count_train)
# print(count_test)

fig, chart = bar_chart(count_train, count_test)
plt.show()
