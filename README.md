# knockout
A tool to help making decisions in case of huge samples. Think, eg., about choosing a movie to watch on Netflix. The idea behind knockout is to split the selections into small chunks, select a favourite in every chunk and knock out the others. After only a few rounds you will have your favourite movie to watch.

Install:
1. Clone repo
2. Download datafile from https://datasets.imdbws.com/title.basics.tsv.gz, unzip and move it into the tests folder
3. Open a terminal in the main folder of the repo and type:
	-mkdir build
	-cd build
	-cmake ..
	-make
4. After the successfull build you can run the tests with
	./knockoutTest
5. Run knockout with
	./knockoutApp
