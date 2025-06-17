Integer Set Class – Laboratory 2.2
📚 Task Description

The objective of this lab assignment is to implement a class representing a set of integers. The class should support:

    Overloading of basic set operations:

        + for union

        - for difference

        * for intersection

    Stream operators for input and output:

        >> for reading a set from user input

        << for printing a set to the console

The set must automatically manage dynamic memory and eliminate duplicate elements during insertion.
🧩 Class Overview: Set

The class Set is implemented with dynamic arrays and supports the following features:
🔧 Constructors & Destructor

    Set() – default constructor

    Set(int* data, int size, int capacity) – parameterized constructor

    Set(const Set& other) – copy constructor

    ~Set() – destructor to release memory

🚀 Core Methods

    insert(int value) – adds an element if it is not already in the set

    contains(int value) – checks if an element exists in the set

    resize() – expands the internal array if needed

⚙️ Operator Overloads

    operator+ – union of two sets

    operator- – difference of two sets

    operator* – intersection of two sets

    operator= – copy assignment

    operator<< – formatted output to a stream

    operator>> – formatted input from a stream

💡 Example Usage

Set s1, s2;
cin >> s1;
cin >> s2;

Set unionSet = s1 + s2;
Set diffSet = s1 - s2;
Set interSet = s1 * s2;

cout << "Union: " << unionSet << endl;
cout << "Difference: " << diffSet << endl;
cout << "Intersection: " << interSet << endl;

✅ Key Characteristics

    No duplicate elements — ensured via internal contains() check.

    Dynamic array resizing — handled with resize() method.

    Operator-based interface — makes the class intuitive and clean to use.

    Encapsulated memory management — proper use of destructors and deep copying.

📎 Files Included

    Set.h – header file with class definition

    Set.cpp – implementation of all methods and operator overloads

    main.cpp – sample usage of the Set class

    README.md – this documentation

🛠️ Compilation

Make sure to compile all source files together:

g++ main.cpp Set.cpp -o set_program

Or if using Visual Studio, include all files in the project solution.
