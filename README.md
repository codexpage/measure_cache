
==== measure the ram size ====
run "make checkmem"

the method to measure ram size is simple. Make use of the trashing. When array size is bigger than available memory size. the part of the memory would be swapped onto disk by OS. Keep malloc 4M block, and test the average time accessing all these blocks every time. When the time sharply increased, that means you are spend time accessing disk because ram is full.

In acutual test, the estimated ram size is 2.5G on my virtual machine which has a 3G memory. I think that because the OS will occupy part of the memory. 





==== measure cache features ====
run "make checkcache"

#on a my laptop virtural machine
my laptop has 32k l1d cache, 128k l2 cache and 3M l3 cache

in the graph , we can see when the array size is below 16K, the time trace is almost a horizontal line. 
But when array size is above 16K, there is a sharp rising up at the 256Byte stride.  That means l1 cache is full, The estimated cache size is smaller than real size, may be threre are other programs running using the cache. 

cache line size is 64Byte on this intel cpu. we can see the increase stop at about 64Btye. That is between the regime 2.a and 2.b. 

The average l1 cache miss delay is about 0.0095ms for 1000 iterations, which is about 9.5ns for each l1 cache miss delay.

The associativity can be figured by look at at the decrease cliff, which is between regime 2.b and 2.c. when s=N/a, the curve start to decrease. And the seems the array 16k start to decrease at 1K and 32K decrease at 2K. It seems the associativity is 16. 


#on ccis machine 

ccis machine has 32k l2d cache, 256K l2cache and 20M l2 cache

the first sharp rising up also happened between 16k and 32K, which means the l1 cache is between 16K and 32K, at this point, l1 cache is full. 
at 256K array size, there is also a big change on the curve. It seems that this is the l2 cache size. 

cache line size seems to be 64Byte by looking at the first small slope. 

The average l1 cache miss delay is about 0.0064ms for iterations, which is about 6.4ns for each l1 cache miss delay.

the associativity is 16 by looking at the decreasing cliff. 

