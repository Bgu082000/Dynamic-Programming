When a new gene is discovered, a standard approach to understanding its function is
to look through a database of known genes and find close matches. The closeness of two genes is measured by
the extent to which they are aligned. To formalize this, think of a gene as being a long string over an alphabet
Σ = {A, C, G, T}. Consider two genes (strings) x and y. An alignment of x and y is a way of matching up these two
strings by lining them up in columns.

For example, if x = ATGCC and y = TACGCA, here are three possible alignments of x and y:

-AT-GCC AT---GCC A-T--G-CC

TA-CGCA T-ACGC-A -TAC--GCA

Here, the “-” character indicates a “gap”. The characters of each string must appear in order, and no column can
contain only gaps. For instance, the following are not valid alignments:

-TA-GCC AT---GCC-

TA-CGCA T--ACGC-A

Any given alignment has a score. The score of an alignment is determined by a 5 × 5 scoring matrix δ, where each
row and column of δ are indexed by one of A, C, G, T, or -. Specifically, the score assigned to an alignment is the
sum over all columns in the alignment of the value δ(a, b), where a is the character from x (or -) that appears in
that column, and b is the character from y (or -) that appears in that column.

Give an algorithm that takes as input two strings x[1 . . n] and y[1 . . m], along with a scoring matrix δ, and returns
the highest-scoring alignment. The running time should be O(mn).



Input Format

The input consists of two lines, where each sequence a and b are the DNA sequences to be scored.


Output Format

First output the optimal score of aligning the two sequences. Then output an optimal alignment of the two sequences.

For this challenge, you are to use the following scoring matrix δ:

-  δ(-,x) = δ(x,-) = -2 for any letter x
-  for all letters x,y: δ(x,y) = +3 if x = y and δ(x,y) = -3 if x != y
