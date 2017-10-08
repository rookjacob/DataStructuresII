All functions should work fine except the cp function. It will copy the name and place a new copy in the
same directory with it's first child, but the rest of the directories bellow it will not be copied.
Guessing its something wrong with the cpRecur function. However, when the cp function is used, it messes up the
data structure so when bye is called and tries to delete all the nodes, it fails for some reason. bye works fine
when the cp function is not called.