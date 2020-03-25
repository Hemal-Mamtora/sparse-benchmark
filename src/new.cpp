// Includes all relevant components of mlpack.
#include <mlpack/core.hpp>
// Convenience.
using namespace mlpack;
int main()
{
  // First, load the data.
  time_t start, end;
  double time_taken; 
  arma::umat data, d, a, b;
  arma::sp_mat sp_data, c;
  // Use data::Load() which transposes the matrix.
  time(&start); 
  data::Load("data/citeseer.edges.csv", data, true);
  time(&end);
  time_taken = double(end - start);
  std::cout<<"Time taken to load a dense matrix of edge list: "
           <<time_taken<<" sec.\n mat.shape: "<<size(data)<<std::endl;

  // std::cout<<data.row(2)<<std::endl;

  arma::umat locations = arma::umat(data.rows( 0, 1));
  arma::Col<arma::u64> values = arma::Col<arma::u64>(data.row(2).t());

  time(&start); 
  arma::SpMat<arma::u64> temp_sp_data = arma::SpMat<arma::u64>(locations, values);
  time(&end);

  time_taken = double(end - start);
  std::cout<<"Time taken to create an adjacency matrix from edge list: "
           <<time_taken<<" sec.\n mat.shape: "<<std::endl;


  //17 SpMat<T1, T2>(const arma::Base<arma::uword, T1> &locations, const arma::Base<double, T2> &values, const bool sort_locations)
  //sp_data = arma::sp_mat(arma::mat(data.rows( 0, 1));
  //arma::umat(data.rows( 0, 1)), arma::colvec(arma::mat(data.row(2).t()))

  // arma::umat locations = data.rows( 0, 1);
  // arma::rowvec values = data.row(2);
  // sp_data = arma::sp_mat(locations, values);

  // std::cout<<data.head_rows(1)<<std::endl;
  // std::cout<<size(data)<<std::endl;
  // Now compute the covariance.  We assume that the data is already centered.
  // Remember, because the matrix is column-major, the covariance operation is
  // transposed.
  // std::cout<<(data * sp_data)<<std::endl;
  // std::cout<<(sp_data * data)<<std::endl;
  // std::cout<<(sp_data * sp_data)<<std::endl;
  // std::cout<<(data * data)<<std::endl;
  // for(int i = 0; i < 10; i++){
  //   sp_data = sp_data * trans(data); 
  //   std::cout<<sp_data<<std::endl;
  // }
  // // std::cout<<"Dense"<<std::endl;
  // std::cout<<cov_dense<<std::endl;
  
  // cov.save("sparse_covariance");
  // cov.save("sparse_covariance.txt", arma::raw_ascii);
  // cov.save("sparse_covariance.csv", arma::csv_ascii);

  
  // Save the output.
  // data::Save("cov.csv", cov, true);
}