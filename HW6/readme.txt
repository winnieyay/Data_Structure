(a)

	一開始將input之數字設成這樣的情況。

	num	|   0  |   1  |   2  |  3  |
	parent   |   0  |   1  |   2  |  3  |
	rank      |  -1  |  -1  |  -1  |  -1 |  

	因應height rule，接下來比較rank(level)來決定parent。
	最後印出數字及其parent。


(d)


Situation 1:
	在這種情況下，我認為weightedUnion和heightUnion的Time complexity是一樣的。因為兩者產生的樹高度皆為2且root皆為0。
Situation 2:
	在樹不等高的情況下，使用weightUnion可能會產生很高的樹，因為是利用node個數來決定的規則。而使用heightUnion則只會產生跟子樹高度最大值一樣的樹，因其是利用height來決定。所以collapsing rule搭配weightUnion較好。
	