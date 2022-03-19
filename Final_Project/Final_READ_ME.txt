Notes on the design drawing:
  The graph layout at the top of the image depicts the default verteces and edges that are created at system start-up. The length of the edges is randomly generated, however, in testing, I had run into a random seed that proved particularly challenging in the errors it caused. That ended up being incredibly helpful when debugging the algorithms as I ran into many niche cases that I very easily could have missed otherwise.
   The lower half of the image is some visualizations I drew as I was working on determining how to proceed in the minimum spanning tree algorithm.

The biggest issue I ran into was coding Dijkstra's. For some reason, that I wasn't able to figure out, the readouts at the end of the function throw out garbage. I wasn't able to fix it, but I take pride in having it "successfully" run to completion.

The minimum spanning tree was moderately easier to tackle. My algorithm was based on Kruskal's and after some work and a lot of thinking, I decided I wanted to try verifying based on which edges had been visited at that point. I was pretty satisfied with the little mutual neighbors helper function I made. Not quite sure why I'm so proud of it, but I am.

I do want to say that this term was very interesting. It was incredibly challenging, but I learned a lot. And while I may still wish I could have taken this class with a better understanding of C++, I do not regret taking the class. I greatly appreciate your dedication to helping students truly learn and I've taken inspiration from that dedication and approach in my own intent and mannerisms as a tutor.

Thank you, Joe, for an incredible term.
