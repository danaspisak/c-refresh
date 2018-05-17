# C Refresh
Code for data-structures and algorithms developed while working on refreshing my C skills. I'm writing about the process at https://luckyfishlab.com. 

Unity test framework and Ceedling build environment are from: http://www.throwtheswitch.org/tools. 

# Data Structures
Singly linked list
Doubly linked list

# Pre-reqs
You'll need Ruby and the 'ceedling' gem. I'm running Ruby 2.5.1. 

I did need to install 'gcovr' to get ceedling to build. There are probably other reqs for things like gcc, but I'm assuming you've built C code in your environment before. 

Install ceedling:
```
gem install ceedling
```

# Run the tests
```
ceedling test:all
```
Output should be somthing like:
```
ceedling test:all


Test 'test_linked-list.c'
-------------------------
Generating runner for test_linked-list.c...
Compiling test_linked-list_runner.c...
Compiling test_linked-list.c...
Compiling unity.c...
Compiling linked-list.c...
Compiling cmock.c...
Linking test_linked-list.out...
Running test_linked-list.out...

--------------------
OVERALL TEST SUMMARY
--------------------
TESTED:  5
PASSED:  5
FAILED:  0
IGNORED: 0
```

# Use Eclipse
I followed the page, http://www.throwtheswitch.org/eclipse/, to get my project in Eclipse. I haven't tried debugging, but it's enough integration to run the tests and see the results. 
