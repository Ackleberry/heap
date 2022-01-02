# Binary Max Heap

TODO:
Work on supporting multiple byte types, making this driver type agnostic.
Allow heap to be configurable MIN/MAX heap. Perhaps with a function pointer?

Problems:
Supporting multiple byte types is difficult. Since we are internally ordering various data types the caller must provide a function that cast the generic buffer data to their type and then make the needed comparision. Right now there needs to be multiple slightly different compare functions implemented by the caller. We should strive to reduce this to 1 function.

Queue, stack, linked list do not have this problem. When you push/pop, the driver only needs to know the size of the data and it will copy it in/out. It is not making any sorting decisions based off this data. The heap is.
