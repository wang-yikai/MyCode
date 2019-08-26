import keras
from keras.layers import Dense, Dropout
from keras.models import Sequential
from keras.datasets import mnist
from keras.utils.np_utils import to_categorical
import numpy as np


def k_fold_split(x_set, y_set, folds=1):
    '''
    Inputs: The x_set data from mnist, the y_set labels from mnist
    Expected Output: The shuffled and K split datasets
    '''
    #gets first dim of x_set
    shuffled_arr = np.arange(x_set.shape[0])
    np.random.shuffle(shuffled_arr)

    #shuffle sets using list-of-locations indexing
    x_shuffled, y_shuffled = x_set[shuffled_arr], y_set[shuffled_arr]

    #splits array into folds sections
    #then flattens the sublists
    x_split = np.array_split(x_shuffled, folds)
    y_split = np.array_split(y_shuffled, folds)

    x_list = []
    for elem in x_split:
        x_list.append([ sub.flatten() for sub in elem ])

    x_folds = np.array(x_list)

    y_list = []
    for elem in y_split:
        y_list.append([ sub.flatten() for sub in elem ])

    y_folds = np.array(y_list)

    return x_folds, y_folds

def construct_model():
    model = Sequential()
    model.add(Dense(512, activation='relu', input_shape=(784,)))
    model.add(Dropout(0.2))
    model.add(Dense(512, activation='relu'))
    model.add(Dropout(0.2))
    model.add(Dense(10, activation='softmax'))
    model.compile(optimizer='RMSprop', loss='categorical_crossentropy', metrics=['accuracy'])
    return model

#Epochs are the number of times the dataset will be iterated over, a good number is 20
def train_model(model, train_dataset, validation_dataset, epochs, name):
    x_set, y_set = train_dataset
    model.fit(x_set, y_set, epochs=epochs, batch_size=128, validation_data=validation_dataset)
    model.save(f'./{name}')

#Hint: Neural Networks can't just handle the lables as they are, they need --categorical-- data
#Note: You must submit the trained models along with the notebook for full credit
def train_validate_k(x_folds, y_folds, num_folds):
    '''
        Inputs: x_folds, the x folds returned from the k_fold algorithm above,
        y_folds the y folds returned from the k_fold algorithm above
        num_folds, the number of folds used to make the x_folds and y_folds
        Expected Output: Nothing, this function has no explicit output,
        but there must be num_fold models trained and saved to disk
    '''
    model = construct_model()
    for i in range(num_folds - 1):
        #to_categorical: Converts a vector of ints to binary class matrix
        train_dataset = (x_folds[i], to_categorical(y_folds[i]))
        validation_dataset = (x_folds[i + 1], to_categorical(y_folds[i + 1]))
        train_model(model, train_dataset, validation_dataset, 20, "model" + chr(ord("A")+i))


(x_set, y_set), (x_test, y_test) = mnist.load_data()
x_set = x_set/255
x_folds, y_folds = k_fold_split(x_set, y_set, 5)
train_validate_k(x_folds, y_folds, 5)

'''
PITFALLS OF CROSS-VALIDATION METHODS

K-fold cross-validation is very sensitive to high-variance data, so having imprecise data points in your set will translate to even more
imprecise predictions. The predictions are not valid at all if the future data does not match the same pattern as the training data. Also,
using multiple data sources in your data would benefit from having those sources in their own separate folds.
'''
