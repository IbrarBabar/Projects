# include<iostream>
# include<math.h>
#include<string>
using namespace std;
int DETERMINANT(int **matrix_1, int nmbr)
{
	int **submatrix = NULL;
	submatrix = new int *[nmbr];
	for (int i = 0; i < nmbr; i++)
	{
		submatrix[i] = new int[nmbr];
	}
	int det = 0;
	if (nmbr == 2)
	{
		return ((matrix_1[0][0] * matrix_1[1][1]) - (matrix_1[1][0] * matrix_1[0][1]));
	}
	else
	{
		for (int x = 0; x < nmbr; x++)
		{
			int subi = 0;
			for (int i = 1; i < nmbr; i++)
			{
				int subj = 0;
				for (int j = 0; j < nmbr; j++)
				{
					if (j == x)
						continue;
					submatrix[subi][subj] = matrix_1[i][j];
					subj++;
				}
				subi++;
			}
			det = det + (pow(-1, x) * matrix_1[0][x] * DETERMINANT(submatrix, nmbr - 1));
		}
	}
	return det;
}
void GetCofactor(int **matrix_1, int **temp1, int p1, int q1, int n1)
{
	int i = 0, j = 0;
	for (int row = 0; row < n1; row++)
	{
		for (int col = 0; col < n1; col++)
		{
			if (row != p1 && col != q1)
			{
				temp1[i][j++] = matrix_1[row][col];
				if (j == n1 - 1)
				{
					j = 0;
					i++;
				}
			}
		}
	}
}
int DETERMINENT(int **matrix_1, int n1)
{
	int D = 0;
	if (n1 == 1)
		return matrix_1[0][0];

	int **temp1 = NULL;
	temp1 = new int *[n1];
	for (int i = 0; i < n1; i++)
	{
		temp1[i] = new int[n1];
	}
	int sign1 = 1;
	for (int f1 = 0; f1 < n1; f1++)
	{
		GetCofactor(matrix_1, temp1, 0, f1, n1);
		D += sign1 * matrix_1[0][f1] * DETERMINENT(temp1, n1 - 1);
		sign1 = -sign1;
	}

	return D;
}
void ADJOINT(int **matrix_1, int **adj1, int n1)
{
	if (n1 == 1)
	{
		adj1[0][0] = 1;
		return;
	}
	int sign1 = 1;
	int **temp = NULL;
	temp = new int *[n1];
	for (int i = 0; i < n1; i++)
	{
		temp[i] = new int[n1];
	}
	for (int i = 0; i<n1; i++)
	{
		for (int j = 0; j<n1; j++)
		{
			GetCofactor(matrix_1, temp, i, j, n1);
			sign1 = ((i + j) % 2 == 0) ? 1 : -1;
			adj1[j][i] = (sign1)*(DETERMINENT(temp, n1 - 1));
		}
	}
}
bool INVERSE(int **matrix_1, float **inverse1, int n1)
{
	int det = DETERMINENT(matrix_1, n1);
	if (det == 0)
	{
		cout << "Determinent is ZERO so Inverse is not possible " << endl;
		return false;
	}
	int **adj = NULL;
	adj = new int *[n1];
	for (int i = 0; i < n1; i++)
	{
		adj[i] = new int[n1];
	}
	ADJOINT(matrix_1, adj, n1);
	for (int i = 0; i < n1; i++)
	{
		for (int j = 0; j < n1; j++)
		{
			inverse1[i][j] = adj[i][j] / float(det);
		}
	}
	return true;
}
void ShowChoices()
{
	cout << "             *********************     Let's Play MATRIX MANIPULATOR       ****************    " << endl;
	cout<<endl;
		cout << " Press 1 for Sum of Matrix  ||  (sum of all values)  " << endl;
		cout << " Press 2 for Product of Matrix  ||  (product of all values) " << endl;
		cout << " Press 3 for Row_wise Average " << endl;
		cout << " Press 4 for Column_wise Average " << endl;
		cout << " Press 5 for Average of whole Matrix " << endl;
		cout << " Press 6 for Row_wise sorting of Matrix" << endl;
		cout << " Press 7 for Column_wise sorting of Matrix" << endl;
		cout << " Press 8 for Scalar Matrix Addition" << endl;
		cout << " Press 9 for Addition of two Matrices" << endl;
		cout << " Press 10 for Scalar Matrix Subtraction" << endl;
		cout << " Press 11 for Subtraction of two Matrices" << endl;
		cout << " Press 12 for Scalar Matrix Multiplication" << endl;
		cout << " Press 13 for Multiplication of two Matrices" << endl;
		cout << " Press 14 for Scalar Matrix Division" << endl;
		cout << " Press 15 for Transpose of Matrix " << endl;
		cout << " Press 16 for Determinant of Matrix " << endl;
		cout << " Press 17 for Matrix Inverse" << endl;
		cout << " If you want to exit program Press 0 !! " << endl;
}

int main()
{
	
	while (1)
	{
		ShowChoices();
		int x;
		cout << " Enter your choice " << endl;
		cin >> x;
		if (x == 0)
		{
			system("pause");
			return 0;
		}
		for (int i = 0; x < 0 || x > 17; i++)
		{
			cout << " Wrong input !!!  " << endl;
			cout << " Please input between 1 to 17  " << endl;
			cin >> x;
			if (x == 0)
			{
				system("pause");
				return 0;
			}
		}
		int **matrix1 = NULL;
		int **matrix2 = NULL;
		int **mult = NULL;
		int **adj = NULL;
		float **inv = NULL;
		int row = 0, column = 0;
		int rowa = 0, columna = 0;
		int num = 0;
		int numa = 0;
		int nums = 0;
		float numd = 0;
		int size = 0;
		int n = 0;
		int d = 0;
		float det = 0;
		cout << " Enter size of row for Matrix " << endl;
		cin >> row;
		for (int i = 0; row <= 0; i++)
		{
			cout << " Wrong input !!!  " << endl;
			cout << " Please input greater than 0  " << endl;
			cin >> row;
		}
		cout << " Enter size of column for Matrix" << endl;
		cin >> column;
		for (int i = 0; column <= 0; i++)
		{
			cout << " Wrong input !!!  " << endl;
			cout << " Please input greater than 0  " << endl;
			cin >> column;
		}
		matrix1 = new int *[row];
		for (int i = 0; i < row; i++)
		{
			matrix1[i] = new int[column];
		}
		cout << "Enter integers for Matrix 1 " << endl;
		for (int i = 0; i < row; i++)
		{
			for (int j = 0; j < column; j++)
			{
				cin >> matrix1[i][j];
			}
			cout << endl;
		}
		cout << "  Matrix 1 is   :  " << endl;
		for (int i = 0; i < row; i++)
		{
			for (int j = 0; j < column; j++)
			{
				cout << " " << matrix1[i][j] << " ";
			}
			cout << endl;
		}
		cout << endl;
		if (x == 1)
		{
			int SUM = 0;
			cout << "  Sum of Matrix (sum of all values)  :   ";
			for (int i = 0; i < row; i++)
			{
				for (int j = 0; j < column; j++)
				{
					SUM = SUM + matrix1[i][j];
				}
			}
			cout << SUM;
			cout << endl;
		}
		else if (x == 2)
		{
			int p1 = 1;
			cout << " Product of Matrix (product of all values)   :  ";
			for (int i = 0; i < row; i++)
			{
				for (int j = 0; j < column; j++)
				{
					p1 = p1*matrix1[i][j];
				}
			}
			cout << p1;
			cout << endl;
		}
		else if (x == 3)
		{
			float S = 0, avgerage = 0;
			int c = 1;
			cout << "  Row-wise Average  :   " << endl;
			for (int i = 0; i < row; i++)
			{
				for (int j = 0; j < column; j++)
				{
					S = S + matrix1[i][j];
				}
				avgerage = S / column;
				cout << " Average of row " << c << " = " << avgerage << endl;
				S = 0;
				c++;
			}
			cout << endl;
		}
		else if (x == 4)
		{
			float S = 0;
			float A = 0;
			int c = 1;
			cout << "   Column-wise Average  " << endl;
			for (int i = 0; i < column; i++)
			{
				for (int j = 0; j < row; j++)
				{
					S = A + matrix1[j][i];
				}
				A = S / row;
				cout << " Average of column " << c << " = " << A << endl;
				S = 0;
				c++;
			}
			cout << endl;
		}
		else if (x == 5)
		{
			int size = 0;
			float avg = 0, sum = 0;
			size = row*column;
			cout << "  Average of whole Matrix :   ";
			for (int i = 0; i < row; i++)
			{
				for (int j = 0; j < column; j++)
				{
					sum = sum + matrix1[i][j];
				}
			}
			avg = sum / size;
			cout << avg;
			cout << endl;
		}
		else if (x == 6)
		{
			cout << " Row-wise sorting of Matrix" << endl;
			for (int i = 0; i < row; i++)
			{
				for (int j = 0; j < column; j++)
				{
					for (int k = 0; k < column - j - 1; k++)
					{
						if (matrix1[i][k] > matrix1[i][k + 1])
						{
							int temp = matrix1[i][k];
							matrix1[i][k] = matrix1[i][k + 1];
							matrix1[i][k + 1] = temp;
						}
					}
				}
			}
			for (int i = 0; i < row; i++)
			{
				for (int j = 0; j < column; j++)
				{
					cout << " " << matrix1[i][j] << " ";
				}
				cout << endl;
			}
			cout << endl;
		}
		else if (x == 7)
		{
			cout << " Column-wise sorting of Matrix" << endl;
			for (int j = 0; j < column; j++)
			{
				for (int i = 0; i < row; i++)
				{
					for (int k = i + 1; k<row; k++)
					{
						if (matrix1[i][j] > matrix1[k][j])
						{
							int temp = matrix1[i][j];

							matrix1[i][j] = matrix1[k][j];

							matrix1[k][j] = temp;
						}
					}
				}
			}
			for (int i = 0; i < row; i++)
			{
				for (int j = 0; j < column; j++)
				{
					cout << " " << matrix1[i][j] << " ";
				}
				cout << endl;
			}
			cout << endl;
		}
		else if (x == 8)
		{
			cout << " Enter a number you want to add with matrix  " << endl;
			cin >> numa;
			cout << "  Scalar Matrix Addition" << endl;
			for (int i = 0; i < row; i++)
			{
				for (int j = 0; j < column; j++)
				{
					cout << " " << numa + matrix1[i][j] << " ";
				}
				cout << endl;
			}
			cout << endl;
		}
		else if (x == 9)
		{
			cout << " Enter size of row for Matrix 2 " << endl;
			cin >> rowa;
			for (int i = 0; rowa <= 0; i++)
			{
				cout << " Wrong input !!!  " << endl;
				cout << " Please input greater than 0  " << endl;
				cin >> rowa;
			}
			for (int i = 0; rowa != row; i++)
			{
				cout << " Wrong input !!!  " << endl;
				cout << " Please input of same size in first matrix  " << endl;
				cin >> rowa;
			}
			cout << " Enter size of column for Matrix 2 " << endl;
			cin >> columna;
			for (int i = 0; columna <= 0; i++)
			{
				cout << " Wrong input !!!  " << endl;
				cout << " Please input greater than 0  " << endl;
				cin >> columna;
			}
			for (int i = 0; columna != column; i++)
			{
				cout << " Wrong input !!!  " << endl;
				cout << " Please input of same size in first matrix  " << endl;
				cin >> columna;
			}
			matrix2 = new int *[rowa];
			for (int i = 0; i < rowa; i++)
			{
				matrix2[i] = new int[columna];
			}
			cout << "Enter integers for Matrix 2 " << endl;
			for (int i = 0; i < rowa; i++)
			{
				for (int j = 0; j < columna; j++)
				{
					cin >> matrix2[i][j];
				}
			}
			cout << "  Matrix 2 is   :  " << endl;
			for (int i = 0; i < rowa; i++)
			{
				for (int j = 0; j < columna; j++)
				{
					cout << " " << matrix2[i][j] << " ";
				}
				cout << endl;
			}
			cout << endl;
			cout << "  Addition of two Matrices" << endl;
			for (int i = 0; i < row; i++)
			{
				for (int j = 0; j < column; j++)
				{
					cout << " " << matrix1[i][j] + matrix2[i][j] << " ";
				}
				cout << endl;
			}
			cout << endl;
		}
		else if (x == 10)
		{
			cout << " Enter a number you want to Subtract with matrix  " << endl;
			cin >> nums;
			cout << "  Scalar Matrix Subtraction" << endl;
			for (int i = 0; i < row; i++)
			{
				for (int j = 0; j < column; j++)
				{
					cout << " " << nums - matrix1[i][j] << " ";
				}
				cout << endl;
			}
			cout << endl;
		}
		else if (x == 11)
		{
			cout << " Enter size of row for Matrix 2 " << endl;
			cin >> rowa;
			for (int i = 0; rowa <= 0; i++)
			{
				cout << " Wrong input !!!  " << endl;
				cout << " Please input greater than 0  " << endl;
				cin >> rowa;
			}
			for (int i = 0; rowa != row; i++)
			{
				cout << " Wrong input !!!  " << endl;
				cout << " Please input of same size in first matrix  " << endl;
				cin >> rowa;
			}
			cout << " Enter size of column for Matrix 2 " << endl;
			cin >> columna;
			for (int i = 0; columna <= 0; i++)
			{
				cout << " Wrong input !!!  " << endl;
				cout << " Please input greater than 0  " << endl;
				cin >> columna;
			}
			for (int i = 0; columna != column; i++)
			{
				cout << " Wrong input !!!  " << endl;
				cout << " Please input of same size in first matrix  " << endl;
				cin >> columna;
			}
			matrix2 = new int *[rowa];
			for (int i = 0; i < rowa; i++)
			{
				matrix2[i] = new int[columna];
			}
			cout << "Enter integers for Matrix 2 " << endl;
			for (int i = 0; i < rowa; i++)
			{
				for (int j = 0; j < columna; j++)
				{
					cin >> matrix2[i][j];
				}
			}
			cout << "  Matrix 2 is   :  " << endl;
			for (int i = 0; i < rowa; i++)
			{
				for (int j = 0; j < columna; j++)
				{
					cout << " " << matrix2[i][j] << " ";
				}
				cout << endl;
			}
			cout << endl;
			cout << " Subtraction of two Matrices" << endl;
			for (int i = 0; i < row; i++)
			{
				for (int j = 0; j < column; j++)
				{
					cout << " " << matrix1[i][j] - matrix2[i][j] << " ";
				}
				cout << endl;
			}
			cout << endl;
		}
		else if (x == 12)
		{
			cout << " Enter a number you want to multiply with matrix  " << endl;
			cin >> num;
			cout << " Scalar Matrix Multiplication" << endl;
			for (int i = 0; i < row; i++)
			{
				for (int j = 0; j < column; j++)
				{
					matrix1[i][j] = num*matrix1[i][j];
				}
			}
			for (int i = 0; i < row; i++)
			{
				for (int j = 0; j < column; j++)
				{
					cout << " " << matrix1[i][j] << " ";
				}
				cout << endl;
			}
			cout << endl;
		}
		else if (x == 13)
		{
			cout << " Enter size of row for Matrix 2 " << endl;
			cin >> rowa;
			for (int i = 0; rowa <= 0; i++)
			{
				cout << " Wrong input !!!  " << endl;
				cout << " Please input greater than 0  " << endl;
				cin >> rowa;
			}
			for (int i = 0; rowa != column; i++)
			{
				cout << " Wrong input !!!  " << endl;
				cout << " Please input row of size equal to column of first matrix  " << endl;
				cin >> rowa;
			}
			cout << " Enter size of column for Matrix 2 " << endl;
			cin >> columna;
			for (int i = 0; columna <= 0; i++)
			{
				cout << " Wrong input !!!  " << endl;
				cout << " Please input greater than 0  " << endl;
				cin >> columna;
			}
			matrix2 = new int *[rowa];
			for (int i = 0; i < rowa; i++)
			{
				matrix2[i] = new int[columna];
			}
			size = row*rowa + column*columna;
			mult = new int *[row];
			for (int i = 0; i < row; i++)
			{
				mult[i] = new int[columna];
			}
			cout << "Enter integers for Matrix 2 " << endl;
			for (int i = 0; i < rowa; i++)
			{
				for (int j = 0; j < columna; j++)
				{
					cin >> matrix2[i][j];
				}
			}
			cout << "  Matrix 2 is   :  " << endl;
			for (int i = 0; i < rowa; i++)
			{
				for (int j = 0; j < columna; j++)
				{
					cout << " " << matrix2[i][j] << " ";
				}
				cout << endl;
			}
			cout << endl;
			cout << " Multiplication of two Matrices" << endl;
			for (int i = 0; i < row; i++)
			{
				for (int j = 0; j < columna; j++)
				{
					mult[i][j] = 0;
					for (int k = 0; k < column; k++)
					{
						mult[i][j] = mult[i][j] + (matrix1[i][k] * matrix2[k][j]);
					}
				}
			}
			for (int i = 0; i < row; i++)
			{
				for (int j = 0; j < columna; j++)
				{
					cout << " " << mult[i][j] << " ";
				}
				cout << endl;
			}
			cout << endl;
		}
		else if (x == 14)
		{
			cout << " Enter a number you want to divide with matrix  " << endl;
			cin >> numd;
			cout << " Scalar Matrix Division" << endl;
			for (int i = 0; i < row; i++)
			{
				for (int j = 0; j < column; j++)
				{
					cout << " " << numd / matrix1[i][j] << " ";
				}
				cout << endl;
			}
			cout << endl;
		}
		else if (x == 15)
		{
			cout << "  Matrix transpose " << endl;
			for (int i = 0; i < column; i++)
			{
				for (int j = 0; j < row; j++)
				{
					cout << " " << matrix1[j][i] << " ";
				}
				cout << endl;
			}
			cout << endl;
		}
		else if (x == 16)
		{
			for (int i = 0; row != column; i++)
			{
				cout << " Wrong input !!!  " << endl;
				cout << " Please input of same size row and column  " << endl;
				cout << " Enter size of row for Matrix" << endl;
				cin >> row;
				for (int i = 0; row <= 0; i++)
				{
					cout << " Wrong input !!!  " << endl;
					cout << " Please input greater than 0  " << endl;
					cin >> row;
				}
				cout << " Enter size of column for Matrix" << endl;
				cin >> column;
				for (int i = 0; column <= 0; i++)
				{
					cout << " Wrong input !!!  " << endl;
					cout << " Please input greater than 0  " << endl;
					cin >> column;
				}

				cout << "Enter integers for Matrix 1 again " << endl;

				for (int i = 0; i < row; i++)
				{
					for (int j = 0; j < column; j++)
					{
						cin >> matrix1[i][j];
					}
				}
				cout << "  Matrix 1 is   :  " << endl;
				for (int i = 0; i < row; i++)
				{
					for (int j = 0; j < column; j++)
					{
						cout << " " << matrix1[i][j] << " ";
					}
					cout << endl;
				}
				cout << endl;
			}
			n = row;
			cout << "Determinant of the matrix is :  " << DETERMINANT(matrix1, n);
			cout << endl;
		}
		else if (x == 17)
		{
			for (int i = 0; row != column; i++)
			{
				cout << " Wrong input !!!  " << endl;
				cout << " Please input of same size row and column  " << endl;
				cout << " Enter size of row for Matrix" << endl;
				cin >> row;
				for (int i = 0; row <= 0; i++)
				{
					cout << " Wrong input !!!  " << endl;
					cout << " Please input greater than 0  " << endl;
					cin >> row;
				}
				cout << " Enter size of column for Matrix" << endl;
				cin >> column;
				for (int i = 0; column <= 0; i++)
				{
					cout << " Wrong input !!!  " << endl;
					cout << " Please input greater than 0  " << endl;
					cin >> column;
				}
				cout << "Enter integers for Matrix 1 again " << endl;
				for (int i = 0; i < row; i++)
				{
					for (int j = 0; j < column; j++)
					{
						cin >> matrix1[i][j];
					}
				}
				cout << "  Matrix 1 is   :  " << endl;
				for (int i = 0; i < row; i++)
				{
					for (int j = 0; j < column; j++)
					{
						cout << " " << matrix1[i][j] << " ";
					}
					cout << endl;
				}
				cout << endl;
			}
			n = row;
			adj = new int *[n];
			for (int i = 0; i < n; i++)
			{
				adj[i] = new int[n];
			}
			inv = new float *[n];
			for (int i = 0; i < n; i++)
			{
				inv[i] = new float[n];
			}
			cout << " The Inverse of Matrix is :  " << endl;
			if (INVERSE(matrix1, inv, n))
			{
				for (int i = 0; i < n; i++)
				{
					for (int j = 0; j < n; j++)
					{
						cout << "  " << inv[i][j] << "  ";
					}
					cout << endl;
				}
			}
		}
		delete[]matrix1;
		delete[]matrix2;
		delete[]mult;
		delete[]adj;
		delete[]inv;
		cout << endl;
	}
	system("pause");
	return 0;
}
