#include<iostream>
using namespace std;
class graph{
	int matrix[10][10];
	int final_matrix[10][10];
	int i_,j_,w_,w;
	int V,E;
	public:
	graph(){
		for(int i=0;i<10;i++){
			for(int j=0;j<10;j++){
				matrix[i][j] = 0;
				final_matrix[i][j] = 0;
			}
		}
		
	}
	void input(){
		
		cout<<"enter number of cities "<<endl;
		cin>>V;
		cout<<"Enter number of paths possible between these  "<<V<<" cities"<<endl;
		cin>>E;
		int v1,v2;
		for(int i=0;i<E;i++){
			cout<<"for the "<<i+1<<" path enter first city number "<<endl;
			cin>>v1;
			cout<<"for the "<<i+1<<" path enter second city number "<<endl;
			cin>>v2;
			cout<<"enter the distance between these two cities "<<endl;
			cin>>w;
			matrix[v1-1][v2-1] = w;
			matrix[v2-1][v1-1] = w;
		}
	}
	void display(){
		cout<<"  ";
		for(int i=0;i<V;i++){
			cout<<i+1<<" ";
		}cout<<endl;
		for(int i=0;i<V;i++){
			cout<<i+1<<" ";
			for(int j=0;j<V;j++){
				cout<<matrix[i][j]<<" ";
			}cout<<endl;
		}
	}
	void find_min(){
		int min =999;
		w_=min;
		for(int i=0;i<V;i++){
			for(int j=0;j<V;j++){
				if((w_ > matrix[i][j])&&(matrix[i][j] != 0)){
					w_=matrix[i][j];
					i_=i;
					j_=j;
				}
			}
		}
	}
	int detect_cycle(){
		int flag =0;
		for(int i=0;i<V;i++){
			if(final_matrix[i_][i] != 0){
				flag =1;
				break;	
			}
		}
		if(flag == 0){
			return 0;
		}
		for(int j=0;j<V;j++){
			if(final_matrix[j][j_] != 0){
				flag = 2;
				break;	
			}
		}
		if(flag == 1){
			return 0;
		}
		else{
			return 1;
		}
	}
	void function(){
		for(int i=0;i<V-1;i++){
			this->find_min();
			int val =this->detect_cycle();
				final_matrix[i_][j_] = w_;
				final_matrix[j_][i_] = w_;
			
			matrix[i_][j_] = 0;
			matrix[j_][i_] = 0;
		}
	}
	void display_final(){
		cout<<endl;
		cout<<"  ";
		for(int i=0;i<V;i++){
			cout<<i+1<<" ";
		}cout<<endl;
		for(int i=0;i<V;i++){
			cout<<i+1<<" ";
			for(int j=0;j<V;j++){
				cout<<final_matrix[i][j]<<" ";
			}cout<<endl;
		}
	}
	void display_result(){
		cout<<" for the minimum cost of cable tv network  the connections are "<<endl;
		for(int i= 0;i<V;i++){
			for(int j=0;j<V;j++){
				if(final_matrix[i][j] != 0){
					cout<<"city "<<i+1<<" connected to  city "<<j+1<<" with distance "<<final_matrix[i][j]<<" kms "<<endl;
					final_matrix[j][i] = 0;
				}
			}
		}
	}
};
int main(){
	graph g;
	g.input();
	g.display();
	g.function();
	g.display_final();
	g.display_result();
}