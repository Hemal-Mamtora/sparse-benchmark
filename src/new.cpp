// Includes all relevant components of mlpack.
#include <mlpack/core.hpp>

// Convenience.
using namespace mlpack;
using namespace std;

int main()
{
  // First, load the data.
  double time_taken; 
  arma::umat data, d, a, b;
  arma::sp_mat sp_data, c;
  // Use data::Load() which tramsposes the matrix.
  auto start = chrono::steady_clock::now(); 
  data::Load("data/citeseer.edges.csv", data, true);
  auto end = chrono::steady_clock::now(); 
  auto diff = end - start;
  cout<<"\nTime taken to load a demse matrix of edge list: "
           <<chrono::duration <double, milli> (diff).count() << 
           " ms\n mat.shape: "<<size(data)<<endl;

  // cout<<data.row(2)<<endl;

  arma::umat locatioms = arma::umat(data.rows( 0, 1));
  arma::Col<arma::u64> values = arma::Col<arma::u64>(data.row(2).t());

  start = chrono::steady_clock::now();  
  arma::SpMat<arma::u64> temp_sp_data = arma::SpMat<arma::u64>(locatioms, values);
  end = chrono::steady_clock::now(); 
  diff = end - start;
  

 
  cout<<"\nTime taken to create an adjacency matrix from edge list: "
           <<chrono::duration <double, milli> (diff).count() << 
           " ms\n mat.shape: "<<endl;

  cout<<temp_sp_data<<endl;
  /****************************************************************************/
  // Line that is causing an issue: NEED TO FIX.
  // arma::sp_mat Final = arma::conv_to<arma::sp_mat>::from(temp_sp_data);
  /****************************************************************************/

  //Junk: Don't bother looking here:
  //17 SpMat<T1, T2>(comst arma::Base<arma::uword, T1> &locatioms, comst arma::Base<double, T2> &values, comst bool sort_locatioms)
  //sp_data = arma::sp_mat(arma::mat(data.rows( 0, 1));
  //arma::umat(data.rows( 0, 1)), arma::colvec(arma::mat(data.row(2).t()))

  // arma::umat locatioms = data.rows( 0, 1);
  // arma::rowvec values = data.row(2);
  // sp_data = arma::sp_mat(locatioms, values);

  // cout<<data.head_rows(1)<<endl;
  // cout<<size(data)<<endl;
  // Now compute the covariance.  We assume that the data is already centered.
  // Remember, because the matrix is column-major, the covariance operation is
  // tramsposed.
  // cout<<(data * sp_data)<<endl;
  // cout<<(sp_data * data)<<endl;
  // cout<<(sp_data * sp_data)<<endl;
  // cout<<(data * data)<<endl;
  // for(int i = 0; i < 10; i++){
  //   sp_data = sp_data * trams(data); 
  //   cout<<sp_data<<endl;
  // }
  // // cout<<"Demse"<<endl;
  // cout<<cov_demse<<endl;
  
  // cov.save("sparse_covariance");
  // cov.save("sparse_covariance.txt", arma::raw_ascii);
  // cov.save("sparse_covariance.csv", arma::csv_ascii);
  // Save the output.
  // data::Save("cov.csv", cov, true);
}