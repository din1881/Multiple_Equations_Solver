#include <iostream>
#include <string>
#include <cstdlib>
#include <sstream>
#include <vector>
using namespace std;

void generalizing(string &str)
{

	vector<string> cutted;
	int findeq = 0;
	int omiteq;
	
	if (str[0] != '+' && str[0] != '-')
	{
		str = '+' + str;
	}
	int foundequal = str.find('=');

	if (str[foundequal + 1] != '+' && str[foundequal + 1] != '-')
	{
		str = str.substr(0, foundequal + 1) + '+' + str.substr(foundequal + 1);
	}


	//cout << "equation ba3d el ta3deel " << str << endl;


	int found = str.find_first_of("+-");
	int count = 0;

	for (int j = 0; j < str.length(); j++)
	{
		if (str[j] == '+' || str[j] == '-')
		{
			count = found;
			found = str.find_first_of("+-", found + 1);

			cutted.push_back(str.substr(count, found - count));
			//cout << "i'm in" << " " << j << " " << count << endl;


		}

		if (str[j] == '=')
		{
			cutted.push_back("=");

			//cout << "i'm out"<<" "<<j<<" "<<count <<endl;
		}

	}
	for (int l = 0; l < cutted.size(); l++)
	{

		if (cutted[l] == "=")
		{
			omiteq = cutted[l - 1].find('=');
			cutted[l - 1] = cutted[l - 1].substr(0, omiteq);
		}


	}
	//cout << "equation met2asema " << endl;
	/*for (int h = 0; h < cutted.size(); h++)
	{
	cout << cutted[h] << endl;
	}*/


	//to check if there exist a constant before equal sign
	int thereEq = 0;
	int foundConst = -1;
	vector<int> constbeforeEq;
	for (int m = 0; m < cutted.size(); m++)
	{
		if (cutted[m] == "=")
		{
			thereEq = m;
			//cout << thereEq << endl;
		}

	}
	//below : finding constants before equal sign and changing their signs
	for (int n = 0; n < thereEq; n++)
	{
		foundConst = cutted[n].find_first_of("_abcdefghijklmnopqrstuvwxyz");
		if (foundConst == -1)
		{
			constbeforeEq.push_back(n);
			//cout << "i'm in" << endl;
		}


	}
	for (int p = 0; p < constbeforeEq.size(); p++)
	{

		if (cutted[constbeforeEq[p]].substr(0, 1) == "+")
		{
			cutted[constbeforeEq[p]] = cutted[constbeforeEq[p]].replace(0, 1, "-");
			//cout << cutted[constbeforeEq[p]] << endl;
		}
		else
		{
			cutted[constbeforeEq[p]] = cutted[constbeforeEq[p]].replace(0, 1, "+");
			//cout << cutted[constbeforeEq[p]] << endl;
		}

	}
	//cout << endl;

	//next we will swap constants before equal them until the equal sign
	string temp;

	for (int p = 0; p < constbeforeEq.size(); p++)
	{
		int q = p;
		if (p != 0)
		{
			constbeforeEq[p] = constbeforeEq[p] - 1;
		}
		int k = constbeforeEq[p];
		for (int d = k; d < thereEq; d++)
		{
			temp = cutted[k];
			cutted[k] = cutted[k + 1];
			cutted[k + 1] = temp;
			k++;

		}
		p = q;
		for (int v = 0; v < cutted.size(); v++)
		{
			if (cutted[v] == "=")
			{
				thereEq = v;
				//cout << thereEq << endl;
			}

		}

	}
	//cout << endl;


	//below : to check if there exist a non constant after equal sign
	int foundnonConst = -1;
	vector<int> nonconstafterEq;
	for (int a = thereEq + 1; a < cutted.size(); a++)
	{
		foundnonConst = cutted[a].find_first_of("_abcdefghijklmnopqrstuvwxyz");
		if (foundnonConst != -1)
		{
			nonconstafterEq.push_back(a);
			//cout << "i'm in" << endl;
		}

	}

	//to change their signs
	for (int b = 0; b < nonconstafterEq.size(); b++)
	{

		if (cutted[nonconstafterEq[b]].substr(0, 1) == "+")
		{
			cutted[nonconstafterEq[b]] = cutted[nonconstafterEq[b]].replace(0, 1, "-");
			//cout << cutted[nonconstafterEq[b]] << endl;
		}
		else
		{
			cutted[nonconstafterEq[b]] = cutted[nonconstafterEq[b]].replace(0, 1, "+");
			//cout << cutted[nonconstafterEq[b]] << endl;
		}

	}
	//cout << endl;

	//below : we will swap nonconstants after equal them until before the equal sign
	string temp2;


	for (int c = 0; c < nonconstafterEq.size(); c++)
	{

		for (int f = nonconstafterEq[c]; f > thereEq; f--)
		{
			temp2 = cutted[f];
			cutted[f] = cutted[f - 1];
			cutted[f - 1] = temp2;

		}
		for (int v = 0; v < cutted.size(); v++)
		{
			if (cutted[v] == "=")
			{
				thereEq = v;
				//cout << thereEq << endl;
			}

		}

	}
	//cout << endl;

	//now we want to add all constnts after equal
	vector<float> elements_of_const;

	for (int o = thereEq + 1; o < cutted.size(); o++)
	{
		float v = atof(cutted[o].c_str());
		elements_of_const.push_back(v);

	}
	//cout << endl;

	float sum_of_constants = 0;

	for (int p = 0; p < elements_of_const.size(); p++)
	{
		sum_of_constants += elements_of_const[p];
	}

	//cout << sum_of_constants << endl;

	//returning sum to string 
	string sum_of_consts;
	ostringstream ss;
	ss << sum_of_constants;
	sum_of_consts = ss.str();
	if (sum_of_constants > 0)
	{
		sum_of_consts = "+" + sum_of_consts;
	}

	for (int x = cutted.size() - 1; x > thereEq; x--)
	{
		cutted.pop_back();
	}

	cutted.push_back(sum_of_consts);

	//if coefficient is one and not written
	string current_element;
	for (int y = 0; y<thereEq; y++)
	{
		current_element = cutted[y];
		int dist_bet_signNvar;

		dist_bet_signNvar = (current_element.find_first_of("_abcdefghijklmnopqrstuvwxyz")) - (current_element.find_first_of("+-"));

		if (dist_bet_signNvar == 1)
		{
			cutted[y] = current_element.substr(0, 1) + "1" + current_element.substr(1);
		}
	}

	//bubble sorting of variables alphabetically
	string tempo;

	for (int i = 0; i < thereEq; i++)
	{


		for (int j = i + 1; j < thereEq; j++)
		{
			if (cutted[i].substr(cutted[i].find_first_of("_abcdefghijklmnopqrstuvwxyz")) > cutted[j].substr(cutted[j].find_first_of("_abcdefghijklmnopqrstuvwxyz")))
			{
				tempo = cutted[i];
				cutted[i] = cutted[j];
				cutted[j] = tempo;
			}
		}
	}


	//add coefficients of repeated variables
	float coeff_sum;
	string new_element;
	string first_var;
	string second_var;

	for (int e = 0; e < 100; e++)
	{
		for (int r = 0; r < thereEq; r++)
		{
			int init = r;
			first_var = cutted[r].substr(cutted[r].find_first_of("_abcdefghijklmnopqrstuvwxyz"));

			for (int i = r + 1; i < thereEq; i++)
			{

				second_var = cutted[i].substr(cutted[i].find_first_of("_abcdefghijklmnopqrstuvwxyz"));
				if (second_var == first_var)
				{
					string coefficient1 = cutted[r].substr(0, cutted[r].find_first_of("_abcdefghijklmnopqrstuvwxyz"));

					string coefficient2 = cutted[i].substr(0, cutted[i].find_first_of("_abcdefghijklmnopqrstuvwxyz"));

					coeff_sum = atof(coefficient1.c_str()) + atof(coefficient2.c_str());

					string coeff_summation;
					ostringstream bb;
					bb << coeff_sum;
					coeff_summation = bb.str();

					if (coeff_sum > 0)
					{
						coeff_summation = "+" + coeff_summation;
					}

					new_element = coeff_summation + second_var;
					//cout << new_element << endl<<endl;
					cutted.erase(cutted.begin() + r, cutted.begin() + r + 2);
					cutted.insert(cutted.begin() + r, new_element);

					for (int v = 0; v < cutted.size(); v++)
					{
						if (cutted[v] == "=")
						{
							thereEq = v;
						}

					}


				}



			}




		}
	}



	for (int v = 0; v < cutted.size(); v++)
	{
		if (cutted[v] == "=")
		{
			thereEq = v;
			//cout << thereEq << endl;
		}

	}
	string first_element = cutted[0];
	string element_after_equal = cutted[thereEq + 1];

	if (first_element[0] == '+')  
	{
		cutted[0] = first_element.substr(1);
	}
	if (element_after_equal[0] == '+')
	{
		cutted[thereEq + 1] = element_after_equal.substr(1);
	}

	string new_str;
	for (int s = 0; s < cutted.size(); s++)
	{

		new_str += cutted[s];

	}
	str = new_str;
	//cout << "the equation became " << str << endl;
}

string add(string equation1, string equation2)
{

	string sum;
	vector<string> coeff_vect1;
	vector<string> var_vect1;
	vector<string> coeff_vect2;
	vector<string> var_vect2;
	vector<float> sum_coeff_num;
	vector<string> sum_coef_str;
	vector<string> new_eq;
	vector<int> not_counted;


	//first: coefficients of 1st equation
	int counter1 = 1;
	int found_next_var = 0;
	int found = 0;
	int foundfirstvar = equation1.find_first_of("_abcdefghijklmnopqrstuvwxyz");
	coeff_vect1.push_back(equation1.substr(0, foundfirstvar));
	for (int i = 1; i < equation1.length(); i++)
	{

		if (equation1[i] == '=')
		{
			coeff_vect1.push_back(equation1.substr(i + 1));
		}
		if ((equation1[i] == '+' || equation1[i] == '-') && (equation1[i - 1] != '='))
		{
			found = equation1.find_first_of("+-", counter1);
			counter1 = found;
			counter1++;
			if (found != -1)
			{

				found_next_var = equation1.find_first_of("_abcdefghijklmnopqrstuvwxyz", found);
				int diff = found_next_var - found;
				coeff_vect1.push_back(equation1.substr(found, diff));

			}
		}
	}





	//second : coefficients of second equation
	int counter2 = 1;
	int found_next_var_2 = 0;
	int found_2 = 0;
	int foundfirstvar_2 = equation2.find_first_of("_abcdefghijklmnopqrstuvwxyz");
	coeff_vect2.push_back(equation2.substr(0, foundfirstvar_2));
	for (int j = 1; j < equation2.length(); j++)
	{

		if (equation2[j] == '=')
		{
			coeff_vect2.push_back(equation2.substr(j + 1));
		}

		if ((equation2[j] == '+' || equation2[j] == '-') && (equation2[j - 1] != '='))
		{
			found_2 = equation2.find_first_of("+-", counter2);
			counter2 = found_2;
			counter2++;
			if (found_2 != -1)
			{

				found_next_var_2 = equation2.find_first_of("_abcdefghijklmnopqrstuvwxyz", found_2);
				int diff_2 = found_next_var_2 - found_2;
				coeff_vect2.push_back(equation2.substr(found_2, diff_2));

			}
		}
	}


	//third: variables of 1st vector
	int thereEq=0;
	int counter3 = 1;
	int found_next_var_3 = 0;
	int found_3 = 0;

	for (int v = 0; v < equation1.length(); v++)
	{
		if (equation1[v] == '=')
		{
			thereEq = v;
		}

	}
	for (int p = 0; p <= thereEq; p++)
	{
		found_next_var_3 = equation1.find_first_of("_abcdefghijklmnopqrstuvwxyz", found_3);
		found_3 = equation1.find_first_of("+-=", counter3);
		if (found_next_var_3 != -1)
		{
			var_vect1.push_back(equation1.substr(found_next_var_3, found_3 - found_next_var_3));
			counter3 = found_3;
			counter3++;
		}
	}


	//fourth: variables of 2nd vector
	int thereEq_2=0;
	int counter4 = 1;
	int found_next_var_4 = 0;
	int found_4 = 0;

	for (int w = 0; w < equation2.length(); w++)
	{
		if (equation2[w] == '=')
		{
			thereEq_2 = w;
		}

	}
	for (int n = 0; n <= thereEq_2; n++)
	{
		found_next_var_4 = equation2.find_first_of("_abcdefghijklmnopqrstuvwxyz", found_4);
		found_4 = equation2.find_first_of("+-=", counter4);
		if (found_next_var_4 != -1)
		{
			var_vect2.push_back(equation2.substr(found_next_var_4, found_4 - found_next_var_4));
			counter4 = found_4;
			counter4++;
		}
	}

	//fifth: getting sum of coefficients
	int flag = 0;
	int flagtoon = 0;
	int counter_of_elements = 0;
	int flag3 = 0;

	if (coeff_vect1.size() > coeff_vect2.size())
	{
		for (int i = 0; i < var_vect1.size(); i++)
		{
			for (int j = 0; j < var_vect2.size(); j++)
			{
				if (var_vect1[i] == var_vect2[j])
				{
					sum_coeff_num.push_back(atof(coeff_vect1[i].c_str()) + atof(coeff_vect2[j].c_str()));
					ostringstream ss;
					ss << sum_coeff_num[counter_of_elements];
					sum_coef_str.push_back(ss.str());
					if (sum_coeff_num[counter_of_elements] >= 0)
					{
						sum_coef_str[counter_of_elements] = "+" + sum_coef_str[counter_of_elements];
					}
					new_eq.push_back(sum_coef_str[counter_of_elements] + var_vect2[j]);
					counter_of_elements++;
					flag = -1;
				}

			}
			if (flag != -1)
			{
				sum_coeff_num.push_back(atof(coeff_vect1[i].c_str()));
				ostringstream dd;
				dd << sum_coeff_num[counter_of_elements];
				sum_coef_str.push_back(dd.str());
				if (sum_coeff_num[counter_of_elements] >= 0)
				{
					sum_coef_str[counter_of_elements] = "+" + sum_coef_str[counter_of_elements];
				}
				new_eq.push_back(sum_coef_str[counter_of_elements] + var_vect1[i]);
				counter_of_elements++;
			}
			flag = 0;
		}

		for (int h = 0; h < var_vect1.size(); h++)
		{
			if (var_vect1[h] == var_vect2[var_vect2.size() - 1])
			{
				flagtoon = -1;
			}

		}

		if (flagtoon != -1)
		{
			sum_coeff_num.push_back(atof(coeff_vect2[coeff_vect2.size() - 2].c_str()));
			ostringstream ee;
			ee << sum_coeff_num[counter_of_elements];
			sum_coef_str.push_back(ee.str());
			if (sum_coeff_num[counter_of_elements] >= 0)
			{
				sum_coef_str[counter_of_elements] = "+" + sum_coef_str[counter_of_elements];
			}
			new_eq.push_back(sum_coef_str[counter_of_elements] + var_vect2[var_vect2.size() - 1]);
			counter_of_elements++;
		}

		new_eq.push_back("=");
		sum_coeff_num.push_back(atof(coeff_vect1[coeff_vect1.size() - 1].c_str()) + atof(coeff_vect2[coeff_vect2.size() - 1].c_str()));
		ostringstream xx;
		xx << sum_coeff_num[counter_of_elements];
		sum_coef_str.push_back(xx.str());
		new_eq.push_back(sum_coef_str[counter_of_elements]);
		counter_of_elements++;


		for (int u = 0; u < new_eq.size(); u++)
		{
			sum += new_eq[u];
		}

	}


	///////////////////////////////////////////////

	if (coeff_vect1.size() < coeff_vect2.size())
	{
		for (int i = 0; i < var_vect2.size(); i++)
		{
			for (int j = 0; j < var_vect1.size(); j++)
			{
				if (var_vect2[i] == var_vect1[j])
				{
					sum_coeff_num.push_back(atof(coeff_vect2[i].c_str()) + atof(coeff_vect1[j].c_str()));
					ostringstream ss;
					ss << sum_coeff_num[counter_of_elements];
					sum_coef_str.push_back(ss.str());
					if (sum_coeff_num[counter_of_elements] >= 0)
					{
						sum_coef_str[counter_of_elements] = "+" + sum_coef_str[counter_of_elements];
					}
					new_eq.push_back(sum_coef_str[counter_of_elements] + var_vect1[j]);
					counter_of_elements++;
					flag = -1;
				}

			}
			if (flag != -1)
			{
				sum_coeff_num.push_back(atof(coeff_vect2[i].c_str()));
				ostringstream dd;
				dd << sum_coeff_num[counter_of_elements];
				sum_coef_str.push_back(dd.str());
				if (sum_coeff_num[counter_of_elements] >= 0)
				{
					sum_coef_str[counter_of_elements] = "+" + sum_coef_str[counter_of_elements];
				}
				new_eq.push_back(sum_coef_str[counter_of_elements] + var_vect2[i]);
				counter_of_elements++;
			}
			flag = 0;
		}

		for (int h = 0; h < var_vect2.size(); h++)
		{
			if (var_vect2[h] == var_vect1[var_vect1.size() - 1])
			{
				flagtoon = -1;
			}

		}

		if (flagtoon != -1)
		{
			sum_coeff_num.push_back(atof(coeff_vect1[coeff_vect1.size() - 2].c_str()));
			ostringstream ee;
			ee << sum_coeff_num[counter_of_elements];
			sum_coef_str.push_back(ee.str());
			if (sum_coeff_num[counter_of_elements] >= 0)
			{
				sum_coef_str[counter_of_elements] = "+" + sum_coef_str[counter_of_elements];
			}
			new_eq.push_back(sum_coef_str[counter_of_elements] + var_vect1[var_vect1.size() - 1]);
			counter_of_elements++;
		}

		new_eq.push_back("=");
		sum_coeff_num.push_back(atof(coeff_vect2[coeff_vect2.size() - 1].c_str()) + atof(coeff_vect1[coeff_vect1.size() - 1].c_str()));
		ostringstream xx;
		xx << sum_coeff_num[counter_of_elements];
		sum_coef_str.push_back(xx.str());
		new_eq.push_back(sum_coef_str[counter_of_elements]);
		counter_of_elements++;


		for (int u = 0; u < new_eq.size(); u++)
		{
			sum += new_eq[u];
		}

	}
	////////////////////////////////////////////////////////////////////
	int flagool = -1;

	int repeated = 0;
	if (coeff_vect1.size() == coeff_vect2.size())
	{
		for (int i = 0; i < var_vect1.size(); i++)
		{
			for (int j = 0; j < var_vect2.size(); j++)
			{
				if (var_vect1[i] == var_vect2[j])
				{
					sum_coeff_num.push_back(atof(coeff_vect1[i].c_str()) + atof(coeff_vect2[j].c_str()));
					ostringstream ss;
					ss << sum_coeff_num[counter_of_elements];
					sum_coef_str.push_back(ss.str());
					if (sum_coeff_num[counter_of_elements] >= 0)
					{
						sum_coef_str[counter_of_elements] = "+" + sum_coef_str[counter_of_elements];
					}
					new_eq.push_back(sum_coef_str[counter_of_elements] + var_vect2[j]);
					counter_of_elements++;
					flag = -1;
					repeated = j;
				}


			}



			if (flag != -1)
			{
				sum_coeff_num.push_back(atof(coeff_vect1[i].c_str()));
				ostringstream dd;
				dd << sum_coeff_num[counter_of_elements];
				sum_coef_str.push_back(dd.str());
				if (sum_coeff_num[counter_of_elements] >= 0)
				{
					sum_coef_str[counter_of_elements] = "+" + sum_coef_str[counter_of_elements];
				}
				new_eq.push_back(sum_coef_str[counter_of_elements] + var_vect1[i]);
				counter_of_elements++;
				flagool = 0;
			}

			flag = 0;
		}

		if (flagool != -1)
		{

			for (int a = 0; a < var_vect2.size(); a++)
			{
				for (int b = 0; b < var_vect1.size(); b++)
				{
					if (var_vect2[a] != var_vect1[b])
					{
						flag3 = -1;
					}
					if (var_vect2[a] == var_vect1[b])
					{

						flag3 = 0;

					}
				}
				if (flag3 == -1)
				{
					not_counted.push_back(a);
				}
			}
			for (int z = 0; z < not_counted.size(); z++)
			{
				if (z != repeated)
				{
					sum_coeff_num.push_back(atof(coeff_vect2[not_counted[z]].c_str()));
					ostringstream ee;
					ee << sum_coeff_num[counter_of_elements];
					sum_coef_str.push_back(ee.str());
					if (sum_coeff_num[counter_of_elements] >= 0)
					{
						sum_coef_str[counter_of_elements] = "+" + sum_coef_str[counter_of_elements];
					}
					new_eq.push_back(sum_coef_str[counter_of_elements] + var_vect2[not_counted[z]]);
					counter_of_elements++;
				}

			}




		}
		new_eq.push_back("=");
		sum_coeff_num.push_back(atof(coeff_vect1[coeff_vect1.size() - 1].c_str()) + atof(coeff_vect2[coeff_vect2.size() - 1].c_str()));
		ostringstream xx;
		xx << sum_coeff_num[counter_of_elements];
		sum_coef_str.push_back(xx.str());
		new_eq.push_back(sum_coef_str[counter_of_elements]);
		counter_of_elements++;


		for (int u = 0; u < new_eq.size(); u++)
		{
			sum += new_eq[u];
		}


	}

	return sum;

}

string subtract(string equation1, string equation2)
{
	string sum;
	vector<string> coeff_vect1;
	vector<string> var_vect1;
	vector<string> coeff_vect2;
	vector<string> var_vect2;
	vector<float> sum_coeff_num;
	vector<string> sum_coef_str;
	vector<string> new_eq;
	vector<int> not_counted;


	//first: coefficients of 1st equation
	int counter1 = 1;
	int found_next_var = 0;
	int found = 0;
	int foundfirstvar = equation1.find_first_of("_abcdefghijklmnopqrstuvwxyz");

	coeff_vect1.push_back(equation1.substr(0, foundfirstvar));
	string firstqeema = equation1.substr(0, foundfirstvar);
	for (int i = 1; i < equation1.length(); i++)
	{

		if (equation1[i] == '=')
		{
			coeff_vect1.push_back(equation1.substr(i + 1));
			string qeema3 = equation1.substr(i + 1);
		}
		if ((equation1[i] == '+' || equation1[i] == '-') && (equation1[i - 1] != '='))
		{
			found = equation1.find_first_of("+-", counter1);
			counter1 = found;
			counter1++;
			if (found != -1)
			{

				found_next_var = equation1.find_first_of("_abcdefghijklmnopqrstuvwxyz", found);
				int diff = found_next_var - found;
				coeff_vect1.push_back(equation1.substr(found, diff));
				string qeema = equation1.substr(found, diff);

			}
		}
	}





	//second : coefficients of second equation
	int counter2 = 1;
	int found_next_var_2 = 0;
	int found_2 = 0;
	int foundfirstvar_2 = equation2.find_first_of("_abcdefghijklmnopqrstuvwxyz");
	coeff_vect2.push_back(equation2.substr(0, foundfirstvar_2));
	string qeema4 = equation2.substr(0, foundfirstvar_2);
	for (int j = 1; j < equation2.length(); j++)
	{

		if (equation2[j] == '=')
		{
			coeff_vect2.push_back(equation2.substr(j + 1));
			string qeema4 = equation2.substr(j + 1);
		}
		if ((equation2[j] == '+' || equation2[j] == '-') && (equation2[j - 1] != '='))
		{
			found_2 = equation2.find_first_of("+-=", counter2);
			counter2 = found_2;
			counter2++;
			if (found_2 != -1)
			{

				found_next_var_2 = equation2.find_first_of("_abcdefghijklmnopqrstuvwxyz", found_2);
				int diff_2 = found_next_var_2 - found_2;
				string qeema = equation2.substr(found_2, diff_2);
				coeff_vect2.push_back(equation2.substr(found_2, diff_2));
				string coeff2 = coeff_vect2.back();

			}
		}
	}


	//third: variables of 1st vector
	int thereEq;
	int counter3 = 1;
	int found_next_var_3 = 0;
	int found_3 = 0;

	for (int v = 0; v < equation1.length(); v++)
	{
		if (equation1[v] == '=')
		{
			thereEq = v;
		}

	}
	for (int p = 0; p <= thereEq; p++)
	{
		found_next_var_3 = equation1.find_first_of("_abcdefghijklmnopqrstuvwxyz", found_3);
		found_3 = equation1.find_first_of("+-=", counter3);
		if (found_next_var_3 != -1)
		{
			var_vect1.push_back(equation1.substr(found_next_var_3, found_3 - found_next_var_3));
			counter3 = found_3;
			counter3++;
		}
	}


	//fourth: variables of 2nd vector
	int thereEq_2;
	int counter4 = 1;
	int found_next_var_4 = 0;
	int found_4 = 0;

	for (int w = 0; w < equation2.length(); w++)
	{
		if (equation2[w] == '=')
		{
			thereEq_2 = w;
		}

	}
	for (int n = 0; n <= thereEq_2; n++)
	{
		found_next_var_4 = equation2.find_first_of("_abcdefghijklmnopqrstuvwxyz", found_4);
		found_4 = equation2.find_first_of("+-=", counter4);
		if (found_next_var_4 != -1)
		{
			var_vect2.push_back(equation2.substr(found_next_var_4, found_4 - found_next_var_4));
			counter4 = found_4;
			counter4++;
		}
	}

	//fifth: getting diff of coefficients
	int flag = 0;
	int flagtoon = 0;
	int counter_of_elements = 0;
	int flag3 = 0;

	if (coeff_vect1.size() > coeff_vect2.size())
	{
		for (int i = 0; i < var_vect1.size(); i++)
		{
			for (int j = 0; j < var_vect2.size(); j++)
			{
				if (var_vect1[i] == var_vect2[j])
				{
					sum_coeff_num.push_back(atof(coeff_vect1[i].c_str()) - atof(coeff_vect2[j].c_str()));
					ostringstream ss;
					ss << sum_coeff_num[counter_of_elements];
					sum_coef_str.push_back(ss.str());
					if (sum_coeff_num[counter_of_elements] >= 0)
					{
						sum_coef_str[counter_of_elements] = "+" + sum_coef_str[counter_of_elements];
					}
					new_eq.push_back(sum_coef_str[counter_of_elements] + var_vect2[j]);
					counter_of_elements++;
					flag = -1;
				}

			}
			if (flag != -1)
			{
				sum_coeff_num.push_back(atof(coeff_vect1[i].c_str()));
				ostringstream dd;
				dd << sum_coeff_num[counter_of_elements];
				sum_coef_str.push_back(dd.str());
				if (sum_coeff_num[counter_of_elements] >= 0)
				{
					sum_coef_str[counter_of_elements] = "+" + sum_coef_str[counter_of_elements];
				}
				new_eq.push_back(sum_coef_str[counter_of_elements] + var_vect1[i]);
				counter_of_elements++;
			}
			flag = 0;
		}

		for (int h = 0; h < var_vect1.size(); h++)
		{
			if (var_vect1[h] == var_vect2[var_vect2.size() - 1])
			{
				flagtoon = -1;
			}

		}

		if (flagtoon != -1)
		{
			sum_coeff_num.push_back(-atof(coeff_vect2[coeff_vect2.size() - 2].c_str()));
			ostringstream ee;
			ee << sum_coeff_num[counter_of_elements];
			sum_coef_str.push_back(ee.str());
			if (sum_coeff_num[counter_of_elements] >= 0)
			{
				sum_coef_str[counter_of_elements] = "+" + sum_coef_str[counter_of_elements];
			}
			new_eq.push_back(sum_coef_str[counter_of_elements] + var_vect2[var_vect2.size() - 1]);
			counter_of_elements++;
		}

		new_eq.push_back("=");
		sum_coeff_num.push_back(atof(coeff_vect1[coeff_vect1.size() - 1].c_str()) - atof(coeff_vect2[coeff_vect2.size() - 1].c_str()));
		ostringstream xx;
		xx << sum_coeff_num[counter_of_elements];
		sum_coef_str.push_back(xx.str());
		new_eq.push_back(sum_coef_str[counter_of_elements]);
		counter_of_elements++;


		for (int u = 0; u < new_eq.size(); u++)
		{
			sum += new_eq[u];
		}

	}


	///////////////////////////////////////////////

	if (coeff_vect1.size() < coeff_vect2.size())
	{
		for (int i = 0; i < var_vect2.size(); i++)
		{
			for (int j = 0; j < var_vect1.size(); j++)
			{
				if (var_vect2[i] == var_vect1[j])
				{
					sum_coeff_num.push_back(-atof(coeff_vect2[i].c_str()) + atof(coeff_vect1[j].c_str()));
					ostringstream ss;
					ss << sum_coeff_num[counter_of_elements];
					sum_coef_str.push_back(ss.str());
					if (sum_coeff_num[counter_of_elements] >= 0)
					{
						sum_coef_str[counter_of_elements] = "+" + sum_coef_str[counter_of_elements];
					}
					new_eq.push_back(sum_coef_str[counter_of_elements] + var_vect1[j]);
					counter_of_elements++;
					flag = -1;
				}

			}
			if (flag != -1)
			{
				sum_coeff_num.push_back(-atof(coeff_vect2[i].c_str()));
				ostringstream dd;
				dd << sum_coeff_num[counter_of_elements];
				sum_coef_str.push_back(dd.str());
				if (sum_coeff_num[counter_of_elements] >= 0)
				{
					sum_coef_str[counter_of_elements] = "+" + sum_coef_str[counter_of_elements];
				}
				new_eq.push_back(sum_coef_str[counter_of_elements] + var_vect2[i]);
				counter_of_elements++;
			}
			flag = 0;
		}

		for (int h = 0; h < var_vect2.size(); h++)
		{
			if (var_vect2[h] == var_vect1[var_vect1.size() - 1])
			{
				flagtoon = -1;
			}

		}

		if (flagtoon != -1)
		{
			sum_coeff_num.push_back(atof(coeff_vect1[coeff_vect1.size() - 2].c_str()));
			ostringstream ee;
			ee << sum_coeff_num[counter_of_elements];
			sum_coef_str.push_back(ee.str());
			if (sum_coeff_num[counter_of_elements] >= 0)
			{
				sum_coef_str[counter_of_elements] = "+" + sum_coef_str[counter_of_elements];
			}
			new_eq.push_back(sum_coef_str[counter_of_elements] + var_vect1[var_vect1.size() - 1]);
			counter_of_elements++;
		}

		new_eq.push_back("=");
		sum_coeff_num.push_back(-atof(coeff_vect2[coeff_vect2.size() - 1].c_str()) + atof(coeff_vect1[coeff_vect1.size() - 1].c_str()));
		ostringstream xx;
		xx << sum_coeff_num[counter_of_elements];
		sum_coef_str.push_back(xx.str());
		new_eq.push_back(sum_coef_str[counter_of_elements]);
		counter_of_elements++;


		for (int u = 0; u < new_eq.size(); u++)
		{
			sum += new_eq[u];
		}

	}
	////////////////////////////////////////////////////////////////////
	int flagool = -1;

	int repeated = 0;
	if (coeff_vect1.size() == coeff_vect2.size())
	{
		for (int i = 0; i < var_vect1.size(); i++)
		{
			for (int j = 0; j < var_vect2.size(); j++)
			{
				if (var_vect1[i] == var_vect2[j])
				{
					sum_coeff_num.push_back(atof(coeff_vect1[i].c_str()) - atof(coeff_vect2[j].c_str()));
					ostringstream ss;
					ss << sum_coeff_num[counter_of_elements];
					sum_coef_str.push_back(ss.str());
					if (sum_coeff_num[counter_of_elements] >= 0)
					{
						sum_coef_str[counter_of_elements] = "+" + sum_coef_str[counter_of_elements];
					}
					new_eq.push_back(sum_coef_str[counter_of_elements] + var_vect2[j]);
					counter_of_elements++;
					flag = -1;
					repeated = j;
				}


			}



			if (flag != -1)
			{
				sum_coeff_num.push_back(atof(coeff_vect1[i].c_str()));
				ostringstream dd;
				dd << sum_coeff_num[counter_of_elements];
				sum_coef_str.push_back(dd.str());
				if (sum_coeff_num[counter_of_elements] >= 0)
				{
					sum_coef_str[counter_of_elements] = "+" + sum_coef_str[counter_of_elements];
				}
				new_eq.push_back(sum_coef_str[counter_of_elements] + var_vect1[i]);
				counter_of_elements++;
				flagool = 0;
			}

			flag = 0;
		}

		if (flagool != -1)
		{

			for (int a = 0; a < var_vect2.size(); a++)
			{
				for (int b = 0; b < var_vect1.size(); b++)
				{
					if (var_vect2[a] != var_vect1[b])
					{
						flag3 = -1;
					}
					if (var_vect2[a] == var_vect1[b])
					{

						flag3 = 0;

					}
				}
				if (flag3 == -1)
				{
					not_counted.push_back(a);
				}
			}
			for (int z = 0; z < not_counted.size(); z++)
			{
				if (z != repeated)
				{
					sum_coeff_num.push_back(-atof(coeff_vect2[not_counted[z]].c_str()));
					ostringstream ee;
					ee << sum_coeff_num[counter_of_elements];
					sum_coef_str.push_back(ee.str());
					if (sum_coeff_num[counter_of_elements] >= 0)
					{
						sum_coef_str[counter_of_elements] = "+" + sum_coef_str[counter_of_elements];
					}
					new_eq.push_back(sum_coef_str[counter_of_elements] + var_vect2[not_counted[z]]);
					counter_of_elements++;
				}

			}




		}
		new_eq.push_back("=");
		sum_coeff_num.push_back(atof(coeff_vect1[coeff_vect1.size() - 1].c_str()) - atof(coeff_vect2[coeff_vect2.size() - 1].c_str()));
		ostringstream xx;
		xx << sum_coeff_num[counter_of_elements];
		sum_coef_str.push_back(xx.str());
		new_eq.push_back(sum_coef_str[counter_of_elements]);
		counter_of_elements++;


		for (int u = 0; u < new_eq.size(); u++)
		{
			sum += new_eq[u];
		}


	}
	return sum;
}

string substitute_eq(string input, string str)
{
	vector<string> cutted;
	if (str[0] != '+' && str[0] != '-')
	{
		str = '+' + str;
	}
	int foundequal = str.find('=');

	if (str[foundequal + 1] != '+' && str[foundequal + 1] != '-')
	{
		str = str.substr(0, foundequal + 1) + '+' + str.substr(foundequal + 1);
	}

	int findeq = 0;
	int omiteq;


	int found = str.find_first_of("+-");
	int count = 0;

	for (int j = 0; j < str.length(); j++)
	{
		if (str[j] == '+' || str[j] == '-')
		{
			count = found;
			found = str.find_first_of("+-", found + 1);

			cutted.push_back(str.substr(count, found - count));
			//cout << "i'm in" << " " << j << " " << count << endl;


		}

		if (str[j] == '=')
		{
			cutted.push_back("=");

			//cout << "i'm out"<<" "<<j<<" "<<count <<endl;
		}

	}
	for (int l = 0; l < cutted.size(); l++)
	{

		if (cutted[l] == "=")
		{
			omiteq = cutted[l - 1].find('=');
			cutted[l - 1] = cutted[l - 1].substr(0, omiteq);
		}


	}

	//find x2 and put it first
	int found_var = 0;
	int my_var = 0;
	string current_elem;
	for (int p = 0; p < cutted.size(); p++)
	{
		current_elem = cutted[p];
		found_var = current_elem.find(input);
		if (found_var != -1)
			my_var = p ;
	}

	cutted.insert(cutted.begin(), cutted[my_var]);
	cutted.erase(cutted.begin() + my_var + 1);


	//divide all eq by coefficient of variable
	found_var = cutted[0].find_first_of("_abcdefghijklmnopqrstuvwxyz");
	float new_coeff = 0;

	float coeff_of_want_var = atof((cutted[0].substr(0, found_var)).c_str());
	int found_equal = 0;
	for (int l = 0; l < cutted.size(); l++)
	{
		if (cutted[l] == "=")
		{
			found_equal = l;
		}
	}

	for (int k = 0; k < found_equal; k++)
	{
		int found_other_var = cutted[k].find_first_of("_abcdefghijklmnopqrstuvwxyz");
		float coeff_of_other_var = atof((cutted[k].substr(0, found_other_var)).c_str());
		new_coeff = coeff_of_other_var / coeff_of_want_var;
		string new_co;
		ostringstream ss;
		ss << new_coeff;
		new_co = ss.str();
		if (new_coeff >= 0)
		{
			new_co = "+" + new_co;
		}

		cutted[k].replace(0, found_other_var, new_co);

	}

	float coeff_of_constant = atof((cutted[cutted.size() - 1]).c_str());
	new_coeff = coeff_of_constant / coeff_of_want_var;
	string new_co;
	ostringstream kk;
	kk << new_coeff;
	new_co = kk.str();
	if (new_coeff >= 0)
	{
		new_co = "+" + new_co;
	}
	cutted[cutted.size() - 1].replace(0, cutted[cutted.size() - 1].length(), new_co);

	//cout << endl << endl;

	//change signs of all elements bet first elment and equal
	for (int o = 1; o < found_equal; o++)
	{
		string signn = cutted[o].substr(0, 1);
		if (signn == "+")
		{
			cutted[o].replace(0, 1, "-");
		}
		if (signn == "-")
		{
			cutted[o].replace(0, 1, "+");
		}
	}

	//move the equal to be after wanted var
	for (int u = found_equal; u > 1; u--)
	{
		string tempe = cutted[u - 1];
		cutted[u - 1] = cutted[u];
		cutted[u] = tempe;


	}
	//remove the first two elements and return string
	cutted.erase(cutted.begin());
	cutted.erase(cutted.begin());

	string sub_eq;
	for (int e = 0; e < cutted.size(); e++)
	{
		sub_eq += cutted[e];
	}

	return sub_eq;
}

int num_vars(vector <string> equations)
{

	vector <string> var_vect1;
	int thereEq = 0;

	for (int i = 0; i < equations.size(); i++)
	{
		string current_eq = equations[i];
		for (int v = 0; v < current_eq.length(); v++)
		{
			if (current_eq[v] == '=')
			{
				thereEq = v;
			}

		}
		int comparison = 0;
		int counter3 = 1;
		int found_next_var_3 = 0;
		int found_3 = 0;
		for (int p = 0; p <= thereEq; p++)
		{

			found_next_var_3 = current_eq.find_first_of("_abcdefghijklmnopqrstuvwxyz", found_3);
			found_3 = current_eq.find_first_of("+-=", counter3);

			if (found_next_var_3 > -1)
			{
				string current_var = current_eq.substr(found_next_var_3, found_3 - found_next_var_3);
				if (var_vect1.size() == 0)
				{
					var_vect1.push_back(current_var);
				}

				for (int j = 0; j <var_vect1.size(); j++)
				{

					comparison = current_var.compare(var_vect1[j]);
					if (comparison == 0)
						break;
				}
				if (comparison != 0)
				{
					var_vect1.push_back(current_var);
				}
				counter3 = found_3;
				counter3++;

			}

		}

	}


	return var_vect1.size();
}

vector <string> new_equations(vector <string> equations)
{
	vector <string> var_vect1;
	int thereEq = 0;

	for (int i = 0; i < equations.size(); i++)
	{
		string current_eq = equations[i];
		for (int v = 0; v < current_eq.length(); v++)
		{
			if (current_eq[v] == '=')
			{
				thereEq = v;
			}

		}
		int comparison = 0;
		int counter3 = 1;
		int found_next_var_3 = 0;
		int found_3 = 0;
		for (int p = 0; p <= thereEq; p++)
		{

			found_next_var_3 = current_eq.find_first_of("_abcdefghijklmnopqrstuvwxyz", found_3);
			found_3 = current_eq.find_first_of("+-=", counter3);

			if (found_next_var_3 > -1)
			{
				string current_var = current_eq.substr(found_next_var_3, found_3 - found_next_var_3);
				if (var_vect1.size() == 0)
				{
					var_vect1.push_back(current_var);
				}

				for (int j = 0; j <var_vect1.size(); j++)
				{

					comparison = current_var.compare(var_vect1[j]);
					if (comparison == 0)
						break;
				}
				if (comparison != 0)
				{
					var_vect1.push_back(current_var);
				}
				counter3 = found_3;
				counter3++;

			}

		}

	}

	vector <string> new_eq;

	for (int r = 0; r < equations.size(); r++)
	{
		for (int x = 0; x < var_vect1.size(); x++)
		{
			int found_my_var = equations[r].find(var_vect1[x]);
			if (found_my_var == -1)
			{
				equations[r] = equations[r] + "-0" + var_vect1[x];
				generalizing(equations[r]);
			}

		}
		new_eq.push_back(equations[r]);
	}
	return new_eq;

}

vector <float> coefficients_of_var(string current_eq)
{
	vector<float> my_coeff_vect;
	int counter = 1;
	int found_next_var = 0;
	int found = 0;
	int foundfirstvar = current_eq.find_first_of("_abcdefghijklmnopqrstuvwxyz");


	my_coeff_vect.push_back(atof((current_eq.substr(0, foundfirstvar)).c_str()));

	for (int i = 1; i < current_eq.length(); i++)
	{

		if ((current_eq[i] == '+' || current_eq[i] == '-') && (current_eq[i - 1] != '='))
		{
			found = current_eq.find_first_of("+-", counter);
			counter = found;
			counter++;
			if (found != -1)
			{

				found_next_var = current_eq.find_first_of("_abcdefghijklmnopqrstuvwxyz", found);
				int diff = found_next_var - found;
				my_coeff_vect.push_back(atof(current_eq.substr(found, diff).c_str()));
				//string qeema = current_eq.substr(found, diff);
			}
		}
	}
	return my_coeff_vect;
}

vector <float> cramers_of_var(string current_eq, string var_name)
{
	vector<float> my_coeff_vect;
	int counter = 1;
	int found_next_var = 0;
	int found = 0;
	int foundfirstvar = current_eq.find_first_of("_abcdefghijklmnopqrstuvwxyz");


	my_coeff_vect.push_back(atof((current_eq.substr(0, foundfirstvar)).c_str()));

	for (int i = 1; i < current_eq.length(); i++)
	{
		if (current_eq[i] == '=')
		{
			my_coeff_vect.push_back(atof((current_eq.substr(i + 1)).c_str()));
		}


		if ((current_eq[i] == '+' || current_eq[i] == '-') && (current_eq[i - 1] != '='))
		{
			found = current_eq.find_first_of("+-", counter);
			counter = found;
			counter++;
			if (found != -1)
			{

				found_next_var = current_eq.find_first_of("_abcdefghijklmnopqrstuvwxyz", found);
				int diff = found_next_var - found;
				my_coeff_vect.push_back(atof(current_eq.substr(found, diff).c_str()));
			}
		}
	}



	vector <string> my_variables;
	int thereEq = 0;
	int counter3 = 1;
	int found_next_var_3 = 0;
	int found_3 = 0;

	for (int v = 0; v < current_eq.length(); v++)
	{
		if (current_eq[v] == '=')
		{
			thereEq = v;
		}

	}
	for (int p = 0; p <= thereEq; p++)
	{
		found_next_var_3 = current_eq.find_first_of("_abcdefghijklmnopqrstuvwxyz", found_3);
		found_3 = current_eq.find_first_of("+-=", counter3);
		if (found_next_var_3 != -1)
		{
			my_variables.push_back(current_eq.substr(found_next_var_3, found_3 - found_next_var_3));
			counter3 = found_3;
			counter3++;
		}
	}
	int this_is_var = 0;
	for (int y = 0; y < my_variables.size(); y++)
	{
		if (var_name == my_variables[y])
		{
			this_is_var = y;
		}
	}


	my_coeff_vect.insert(my_coeff_vect.begin() + this_is_var, my_coeff_vect[my_coeff_vect.size() - 1]);
	my_coeff_vect.erase(my_coeff_vect.begin() + this_is_var + 1);
	my_coeff_vect.erase(my_coeff_vect.begin() + my_coeff_vect.size() - 1);


	return my_coeff_vect;
}

double det_solver(vector <float> my_coeff)
{
	double answer = 0;
	if (my_coeff.size() == 4)
	{
		answer = (my_coeff[0] * my_coeff[3]) - (my_coeff[1] * my_coeff[2]);
	}
	if (my_coeff.size() == 9)
	{
		double a, b, c;
		a = my_coeff[0] * ((my_coeff[4] * my_coeff[8]) - (my_coeff[5] * my_coeff[7]));
		b = my_coeff[1] * ((my_coeff[3] * my_coeff[8]) - (my_coeff[5] * my_coeff[6]));
		c = my_coeff[2] * ((my_coeff[3] * my_coeff[7]) - (my_coeff[4] * my_coeff[6]));
		answer = a - b + c;
	}
	return answer;
}

vector <string> get_var(string current_eq)
{
	vector<string> var_vect;
	int thereEq = 0;
	int counter3 = 1;
	int found_next_var_3 = 0;
	int found_3 = 0;

	for (int v = 0; v < current_eq.length(); v++)
	{
		if (current_eq[v] == '=')
		{
			thereEq = v;
		}

	}
	for (int p = 0; p <= thereEq; p++)
	{
		found_next_var_3 = current_eq.find_first_of("_abcdefghijklmnopqrstuvwxyz", found_3);
		found_3 = current_eq.find_first_of("+-=", counter3);
		if (found_next_var_3 != -1)
		{
			var_vect.push_back(current_eq.substr(found_next_var_3, found_3 - found_next_var_3));
			counter3 = found_3;
			counter3++;
		}
	}
	return var_vect;
}





int main() {
	string input;
	string eq;
	vector <string> equations;
	
	int n=0;
	cin >> n;

	int counter = 0;
	
	
	for (int i = 0; i < n; i++)
	{
		cin >> eq;
		equations.push_back(eq);
	}


	for (int k = 0; k <equations.size(); k++)
	{
		generalizing(equations[k]);
	}

	do 
	{
		getline(cin, input);
		int inputlength = input.length();
		string eqComp = input.substr(0, 8);
		string columncomp = input.substr(0,6);
		string addComp = input.substr(0, 3);
		string subtractcomp = input.substr(0,8);
		
		//if input is number of variables
		if (input == "num_vars")
		{
			cout << num_vars(equations) << endl;
			
		}


		//if input is equation number
		if (eqComp == "equation")
		{
			string no = input.substr(9, inputlength);

			int numOfEq;
			numOfEq = atoi(no.c_str());
			cout << equations[numOfEq-1] << endl;
		}
		

		//if input is specific column
		string number;
		if (columncomp == "column")
		{
			vector<string> new_eq;
			string var_name = input.substr(7);
			vector<string> column;
			new_eq = new_equations(equations);
			
			for (int l = 0; l <new_eq.size(); l++)
			{
				
				string current_eq = new_eq[l];
				int found = current_eq.find(var_name);
				for (int j = 0; found == current_eq.find(var_name);  j++)
				{
					if (found == current_eq.find(var_name))
					{	
						string test_string = current_eq.substr(0, found + 1);
						int foundplusminus = test_string.find_last_of("+-");
						if (foundplusminus != -1) 
						{
							number = current_eq.substr(foundplusminus, found - foundplusminus);
						}
						else 
						{
							number = current_eq.substr(0, found);
						}
						
						if (number[0]=='+') 
						{
							number = number.substr(1);
						}
						column.push_back(number);
						break;
					}
				}
			}
			
			for (int t = 0; t < column.size(); t++)
			{
				cout << column[t] << endl;
			}
		}

		//if input is add 2 equations
		if (addComp == "add") 
		{
			string str_of_fir_eq = input.substr(4,1);
			string str_of_sec_eq = input.substr(6,1);
			int no_of_fir_eq = atoi(str_of_fir_eq.c_str());
			int no_of_sec_eq = atoi(str_of_sec_eq.c_str());
			string sum_str;
			sum_str = add(equations[no_of_fir_eq-1], equations[no_of_sec_eq-1]);
			generalizing(sum_str);
			cout << sum_str;
		}

		//if input is subtract 2 equations
		
		if (subtractcomp == "subtract")
		{
			string str_of_fir_eq = input.substr(9, 1);
			string str_of_sec_eq = input.substr(11, 1);
			int no_of_fir_eq = atoi(str_of_fir_eq.c_str());
			int no_of_sec_eq = atoi(str_of_sec_eq.c_str());
			string sum_str;
			sum_str = subtract(equations[no_of_fir_eq-1], equations[no_of_sec_eq-1]);
			generalizing(sum_str);
			cout << sum_str;
		}

		//if input is subsitute

		if (input.substr(0, 10)=="substitute")
		{
			
			int found_first_space = input.find_first_of(" ");
			int found_next_space = input.find_first_of(" ", found_first_space + 1);
			string variable_look = input.substr(input.find_first_of(" ")+1, found_next_space-found_first_space-1);
			int found_next_space_2 = input.find_first_of(" ", found_next_space + 1);
			int no_of_eq_1 = atoi((input.substr(found_next_space + 1, found_next_space_2 - found_next_space)).c_str());
			int no_of_eq_2 = atoi((input.substr(found_next_space_2 + 1)).c_str());


			string new_equation = substitute_eq(variable_look, equations[no_of_eq_1 - 1]) + "=" + substitute_eq(variable_look, equations[no_of_eq_2 - 1]);
			generalizing(new_equation);
			cout << new_equation << endl;
		}

		//if input is D_operation

		if (input == "D")
		{
			vector<string> new_eq_2;
			new_eq_2 = new_equations(equations);
			for (int k = 0; k < new_eq_2.size(); k++)
			{
				vector<float> my_coeff_vect;
				my_coeff_vect = coefficients_of_var(new_eq_2[k]);
				for (int h = 0; h < my_coeff_vect.size(); h++)
				{
					cout << my_coeff_vect[h] << "\t";
				}
				cout << endl;
			}


		}

		//if input is for ex: D x1

		if (input.substr(0, 1) == "D" && input.length() > 1 && input != "D_value")
		{

			string var_name = input.substr(2);

			vector<string> new_eq_3;
			new_eq_3 = new_equations(equations);
			for (int k = 0; k < new_eq_3.size(); k++)
			{
				vector<float> my_coeff_vect;
				my_coeff_vect = cramers_of_var(new_eq_3[k], var_name);

				for (int h = 0; h < my_coeff_vect.size(); h++)
				{
					cout << my_coeff_vect[h] << "\t";
				}
				cout << endl;
			}
		}

		if (input == "D_value")
		{
			vector<string> new_eq_2;
			new_eq_2 = new_equations(equations);

			for (int j = 0; j < new_eq_2.size(); j++)
			{
				generalizing(new_eq_2[j]);
			}

			vector <string> my_var;
			my_var = get_var(new_eq_2[0]);
			vector <float> my_coeff_vect;
			vector<float> all_coef;
			vector<float> all_coef_2;
			for (int k = 0; k < new_eq_2.size(); k++)
			{
				my_coeff_vect = coefficients_of_var(new_eq_2[k]);
				for (int d = 0; d < my_coeff_vect.size(); d++)
				{
					all_coef.push_back(my_coeff_vect[d]);
				}
				my_coeff_vect.clear();
			}

			double value_of_det = det_solver(all_coef);

			cout << value_of_det << endl;
		}

		if (input == "solve")
		{
			int num_of_vars = num_vars(equations);
			if (num_of_vars != n)
			{
				cout << "No Solution" << endl;
				break;
			}
			vector<string> new_eq_2;
			new_eq_2 = new_equations(equations);

			for (int j = 0; j < new_eq_2.size(); j++)
			{
				generalizing(new_eq_2[j]);
			}

			vector <string> my_var;
			my_var = get_var(new_eq_2[0]);
			vector <float> my_coeff_vect;
			vector<float> all_coef;
			vector<float> all_coef_2;
			for (int k = 0; k < new_eq_2.size(); k++)
			{
				my_coeff_vect = coefficients_of_var(new_eq_2[k]);
				for (int d = 0; d < my_coeff_vect.size(); d++)
				{
					all_coef.push_back(my_coeff_vect[d]);
				}
			}

			double value_of_det = det_solver(all_coef);

			//cout << value_of_det << endl;


			for (int l = 0; l < my_var.size(); l++)
			{
				vector<float> my_coeff_vect_2;
				for (int k = 0; k < new_eq_2.size(); k++)
				{

					my_coeff_vect_2 = cramers_of_var(new_eq_2[k], my_var[l]);
					for (int d = 0; d < my_coeff_vect_2.size(); d++)
					{
						all_coef_2.push_back(my_coeff_vect_2[d]);
					}
				}
				double value_of_det_curr_var = det_solver(all_coef_2);
				double answer = value_of_det_curr_var / value_of_det;
				cout << my_var[l] << "=" << answer << endl;
				my_coeff_vect_2.clear();
				all_coef_2.clear();
			}

		}

	} while (input != "quit");




	system("pause");
	return 0;
}
