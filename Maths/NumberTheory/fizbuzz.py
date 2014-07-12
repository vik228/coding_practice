'''
The fizzbuzz problem is as follows....
we have to print the numbers from 1 to 100 and the condition is ..if the number is a multiple of 3 print Fizz if multiple of 5 print buzz else print FizzBuzz

Here is a simple python code...

author : vikas pandey

Not much python capablities are required for this code...u just need to know about the syntax and the language constructs which i was familier with.....
'''
for i in range (1, 101):
	if i%15 == 0:           
		print "FizzBuzz"
	elif i % 3 == 0:
		print "Fizz"
	elif i % 5 == 0:
		print "Buzz"
	else:
		print i
