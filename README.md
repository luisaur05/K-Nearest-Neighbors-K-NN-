# K-Nearest Neighbors (K-NN) Classification Project in C

## Description

This project implements the K-Nearest Neighbors (K-NN) classification algorithm using the C programming language. The main objective of this project is to classify flowers from the Iris dataset based on their physical attributes, such as the length and width of sepals and petals. The program splits the dataset into two parts: one for training and the other for testing. Then, it classifies the flowers using the K-NN algorithm and evaluates the accuracy of the predictions.

## Project Structure

The program consists of a single C implementation that performs the following tasks:

1. **Data File Reading**: Flower data (attributes and classes) are read from a file called `iris.data`.
2. **K-NN Algorithm Implementation**: The K-NN algorithm is used to classify flowers based on their attributes.
3. **Accuracy Calculation**: The program calculates the percentage of correct classifications by comparing the predicted class labels with the actual class labels from the testing set.

### Files

- `iris.data`: The file containing the Iris dataset. This file should be located in the same directory as the compiled executable.
- `main.c`: The implementation of the program containing the K-NN algorithm logic.

## Usage

### Requirements

- C Compiler (such as `gcc`).
- `iris.data` file containing the Iris dataset.

### Instructions

1. **Compile the Program**:
   To compile the code, use the following command in the terminal:

   ```bash
   gcc -o knn_classifier main.c -lm
   ```

   The `-lm` flag is required to link the math library, as the `sqrt` function is used in distance calculations.

2. **Run the Program**:
   Once compiled, run the program with the following command:

   ```bash
   ./knn_classifier
   ```

3. **Input Parameters**:
   Upon running the program, you will be prompted to enter the following:
   
   - The value of `k` (the number of nearest neighbors to consider).
   - The percentage of data to use for training (between 0 and 100).
   
   For example:
   
   ```
   Enter the value of k for the algorithm: 3
   Enter the percentage of training data for the algorithm (0 to 100): 80
   ```

   The program will use the specified value of `k` for the K-NN algorithm and divide the dataset into training and testing sets based on the entered percentage.

4. **Results**:
   The program will display the classification result for each testing point, indicating whether the prediction was correct or incorrect. At the end, it will display the overall accuracy percentage.

### Example Output

```
Enter the value of k for the algorithm: 3
Enter the percentage of training data for the algorithm (0 to 100): 80
testing *1 = Iris-setosa -----> testing 1 = Iris-setosa // Correct
testing *2 = Iris-setosa -----> testing 2 = Iris-setosa // Correct
...
The classification accuracy is: 96.00%
```

## Code Explanation

- **Data Structures**:
  - `Punto`: A structure that stores the attributes of each flower, including its class.
  - `DistanciaIndice`: A structure used to store the distance of each point from the test point and its index in the dataset.
  
- **Main Functions**:
  - `DistanciaEuclidiana`: Computes the Euclidean distance between two points (flowers).
  - `KNN`: Performs the classification using the K-NN algorithm. It calculates the distances between the test point and all training points, then determines the most frequent class among the k nearest neighbors.

- **Classification Algorithm**:
  - The dataset is split into training and testing sets, and the K-NN algorithm is applied to predict the class of each testing point. The accuracy is then calculated by comparing the predicted classes with the true classes.

## Considerations

- The dataset used is the famous Iris dataset, which contains 150 data points with 4 numerical attributes and a class label for each sample (Setosa, Versicolor, Virginica).
- The value of `k` should be an odd number to avoid ties in classification.

## Conclusion

This project demonstrates how to implement the K-Nearest Neighbors (K-NN) algorithm in C for performing data classification tasks. It is a practical example of using K-NN for classification in machine learning.
