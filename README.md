Benchmarking arma::sp_mat in mlpack

Compile:
g++ src/new.cpp -fopenmp -lmlpack -larmadillo -o bin/new.o

Run:
./bin/new.o 

Output(directly from terminal):
Time taken to load a dense matrix of edge list: 10.4777 ms
 mat.shape: 3x4536

Time taken to create an adjacency matrix from edge list: 5.48914 ms
 mat.shape: 3244x3265

All conversions successful

Timing arma::sp_mat * arma::sp_mat
Time taken for : arma::sp_mat * arma::sp_mat: 6.69302 ms
 mat.shape: 3244x3244

Timing arma::mat * arma::mat
Time taken for : arma::mat * arma::mat: 821.454 ms
 mat.shape: 3244x3244

Timing arma::sp_mat * arma::mat
Time taken for : arma::sp_mat * arma::mat: 579.223 ms
 mat.shape: 3244x3244

Timing arma::mat * arma::sp_mat
Time taken for : arma::mat * arma::sp_mat: 154.473 ms
 mat.shape: 3244x3244

Timing SPARSE arma::mat * arma::sp_mat
Time taken for : arma::mat * arma::sp_mat: 221.396 ms
 mat.shape: 3244x3244

Timing SPARSE arma::sp_mat * arma::mat
Time taken for : arma::sp_mat * arma::mat: 642.525 ms
 mat.shape: 3244x3244