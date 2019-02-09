# Algorithms

![img](https://www.computerhope.com/jargon/a/algorithm.jpg)


## Algorithms

Input -> Algorithm -> Output


>A cooking recipe could be considered an algorithm, thus, the first algorithm could go back as far as when writing began. However, many find Euclid's algorithm for finding the greatest common divisor to be the first. This algorithm that was first described in 300 B.C. by Ada Lovelace, who is credited to be the first computer programmer and the first person to develop an algorithm for a machine.


We always need to specify the pre and post conditions.

#### Pre-Condition: What has to be true about the input for the algorithm to behave as advertised.
##### Ex: factorial(n), pre-cond: n>0

#### Post-Condition: The expected output after the execution of the algorithm.
##### Ex: A[] = {39, 56, 21}; sort(A); Output -> A[] = {21, 39, 56}


#### Correctness: Needless to mention, your Algorithm must return the correct result. Suprisingly, quite often it does not... You'll see!

#### Cost: We are concerned about two types of cost. Memory use and Runtime (or number of CPU cycles being used).

How do we calculate this? Should we count the number of lines of code? Should we add every single bit being transferred through the OS and then through different parts of the hardware and then through the network?

No. Fortunately Big-O makes life simpler than that ! :D

#### Big-O Notation: Big-O is an asymptotic notation that defines the upper bound on the growth rate of the algorithmic runtime. The algorithmic runtime can be characterised as f(n).

The letter O is used because the growth rate of a function is also referred to as the order of the function.

#### Growth Rate: Answers the question, "How does the algorithm scale with the input size?"

Examples of Growth functions: n, n<sup>2</sup>, n<sup>3</sup>, 2<sup>n</sup> etc.


### We will cover examples of 1, n and n<sup>2</sup>.

#### The following is a code fragment from an algorithm that executes a constant number of statements. Thus it is O(1).

```cpp
cout<<"Learning Big-O";
```

#### If the number of executions depend on a variable then we have a higher than constant growth rate. In the following code fragment, n is a user input. As the size of n increases, the number of times the for loop executes the cout also increases. Thus it is O(n), which means the growth rate linearly increases with the size of n.

```cpp
for(int i = 1; i < n; i++){
  cout<<"Learning Big-O";
}
```

#### In the following example we have a for loop within a for loop, a nested scenario. We see that in this case the value of n plays an even bigger role. We see a scenario where the growth rate is quadratic. Thus, it is O(n<sup>2</sup>).

```cpp
for(int i = 1; i < n; i++){
  for(int j = 1; j < n; j++){
    cout<<"Learning Big-O";
  }
}
```

#### Who can tell me what happens when the number of steps reduce by half at every step?

In more advanced courses you will take a deeper dive and learn more about asymptotic notations. For this course a thorough understanding of the covered concepts should help you analyse the complexity of you programs in this course.
