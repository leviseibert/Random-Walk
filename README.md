# Random-Walk

Project Instructions:

The local town drunk, Harvey, has gotten himself into a mess.  Besides being in his normal state, a state that earned him his title, he has made his way into the Flowers Unlimited Park, a park where many flowers are grown and display in their natural beauty.  The local ordinance fines individuals $4.00 for each flower they pick or destroy.  This is enforced to insure the beauty and the integrity of the park.  Now old Harv is not only in the wrong state, drunk, and in the wrong place, the park, he is also on a small island within the park, thirteen feet wide by 12 feet long with a clear path down the middle of the island.  The island is connected to the main land by two bridges one at each end of the island.  Now Harv needs to get across the island and in the process, it will cost him (ie stepping on flowers to get off the island).

There is a clear path down the middle of the island that leads from one bridge to the other (ie no flowers).  The remainder of the island has flowers.  On the island, there are two flowers growing per square foot.  What we need to find out is how much is it going to cost Old Harv to walk from where he is, the end of the walkway, onto the island (ie first step forward puts Harvey on the island) to the far end of the walkway and to get off the island.  The simulation starts when Harvey steps onto the island.

After studying Harvey for many years, it is known that he doesn't walk a straight line when he is in his preferred state.  His walking patterns are as follows.  He steps forward 44% of the time, he steps right 27% of the time, left 21% and backwards 8% of the time.  If Harvey steps onto the far end of the island on to the bridge, we will consider that he has made it across the island.  If he steps into the water, he has finished walking and must be rescued.  If he steps off the path onto a square containing two flowers, he destroys one.  If he steps into the same square later, he destroys the second flower. If he steps into the same square any other times, there are no flowers and it cost nothing.

Write a program that will compute the cost of Harvey's walk in the park.

Inputs:	None
Outputs:	The cost (average) of Harvey's walk.
	The number of times Harvey made it across the island.
	The number of times Harvey had to be rescued from the water.
Restrictions:	Use a 2-d array.  Run the simulation 7000 times to generate the results.
	A simulation Walk does not start until Harvey steps on to the island.
Output:	Format output in a readable style.

Files:
View the source code in Random Walk.cpp and view the output in RandomWalkData.txt
