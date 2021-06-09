# Math 24 Games Reports

##### Members:
- Dido Fabian Fayed       
  (05111940000059) 
- Vyra Fania Adelia       
  (05111940000109)
- Fidhia Ainun Khofifah   
  (05111940000203)


### Project Description

An implementation of 24 card games using depth first search algorithm with 4 input numbers. Each card contains a number 1 to 9. With 4 entered numbers, the 4 numbers must operated through some operators + (add), - (substract), / (divide), * (multiply), (, ) (bracket) to get 24 for the value.

For the example,
We have 2, 1, 3, 8 for the input numbers, the output will be shown 1 and the . It means that the calculation result of the formula is 24.
Explanation: (2-1) * 3 * 8

### Algorithm Description

We implement the depth first search algorithm in Search24_rec() function, where we use a recurrent approach. First we choose two numbers and try different operations for the solution. Then check if we can get 24 with the rest of the numbers and one of the result.

### Analysis
