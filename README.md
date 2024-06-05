I'd be glad to create a README file incorporating the best aspects of both responses A and B, addressing their shortcomings based on the ratings, and adhering to the guidelines:

**CS-112 Final Semester Project: Clustering using OOP in C++/CLI**

This project implements a clustering technique using an Object-Oriented Programming (OOP) approach in C++.

**Project Members**

* Muhammad Ahmad Amjad (2023361)
* Abdullah Ejaz Janjua (2023038)

**Project Overview**

The project consists of three main tasks:

1. **Calculation Correlation Matrix and Discretization:**
    * Calculate the Pearson Correlation Matrix.
    * Discretize the correlation matrix.
    * Visualize the discretized matrix as a zoomable bitmap image.
2. **Permutation and Signature Technique:**
    * Permute the data matrix.
    * Implement the signature technique to recover image clusters.
    * Visualize the sorted and rearranged matrix.
3. **User Interface (UI):** (Not included in this code)
    * Develop an intuitive GUI for user interaction.

**Implemented functionalities (C++ Code):**

* **Task 1:**
    * `CalPearsonCoefficeint`: Calculates the Pearson Correlation Coefficient.
    * `DiscretizeMatrix`: Discretizes the correlation matrix.
    * `Bitmap_Image_Generator`: Generates a bitmap image from the matrix.
    * `max_value`: Scales the values in the correlation matrix for color-coding.
    * `green_shade`: Applies a green shade to the image based on scaled values.
* **Task 2:**
    * `shuffle_matrix`: Permutes the data matrix.
    * `Find_Signature_Values`: Calculates signature values for each row in the permuted matrix.
    * `sort_permutated_matrix`: Sorts the similarity matrix based on signature values.

**Work Distribution**

* **Task 1:** Collaborative effort between both team members.
    * Ahmad Amjad implemented `Bitmap_Image_Generator` and `green_shade`.
    * Abdullah Ejaz Janjua implemented Pearson's correlation coefficient calculation.
    * Both worked on data reading and debugging file reading issues.
* **Task 2:**
    * Ahmad Amjad implemented signature value calculation (`Find_Signature_Values`).
    * Abdullah Ejaz Janjua implemented data matrix permutation (`shuffle_matrix`).
    * Both collaborated on the sorting algorithm (`sort_permutated_matrix`).
* **UI:** Not included in this code, but teamwork was used for design and development.

**Conclusion**

This project demonstrates the successful implementation of a clustering technique using OOP in C++/CLI.  The project highlights effective teamwork and collaboration between team members.

**View the Code Repository**

This project's code can be found on the following GitHub repository:

* Muhammad Ahmad Amjad's GitHub Profile: [https://github.com/amjad]([https://github.com/amjad](https://github.com/ahmadamjadd))
