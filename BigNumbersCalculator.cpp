#include <iostream>
#include <cmath>
#include <stdlib.h>
#include <string>
#include <vector>
#include <sstream>
#include <stdio.h>
#include <bits/stdc++.h>
#include <algorithm>


using namespace std;


void addtion(string number_1, string number_2, string character="+"){

    if (number_1.length() > number_2.length()){
        swap(number_1, number_2);
    }

    string result = "";

    int difference = number_2.length() - number_1.length();
    int tmp = 0;

    for (int i=number_1.length()-1; i>=0; i--)
    {
        int sum = ((number_1[i]-'0') +
                   (number_2[i+difference]-'0') +
                   tmp);
        result.push_back(sum%10 + '0');
        tmp = sum/10;
    }

    for (int i=number_2.length()-number_1.length()-1; i>=0; i--)
    {
        int sum = ((number_2[i]-'0')+tmp);
        result.push_back(sum%10 + '0');
        tmp = sum/10;
    }

    if (tmp){
        result.push_back(tmp+'0');
    }

    if(character == "-" && result != "0"){
        result.push_back('-');

    }

    reverse(result.begin(), result.end());

    cout << result << endl;
}

bool is_smaller(string number_1, string number_2){

    int length_1 = number_1.length();
    int length_2 = number_2.length();

    if (length_1 < length_2)
        return true;
    if (length_2 < length_1)
        return false;

    for (int i = 0; i < length_1; i++) {
        if (number_1[i] < number_2[i])
            return true;
        else if (number_1[i] > number_2[i])
            return false;
    }
    return false;
}

void substraction(string number_1, string number_2){

    string character;

    if (is_smaller(number_1, number_2)){
        swap(number_1, number_2);
        character = "-";
    }
    else{
        character = "+";
    }

    string result = "";

    int length_1 = number_1.length();
    int length_2 = number_2.length();
    int difference_dlugosci = length_1 - length_2;

    int tmp = 0;

    for (int i = length_2 - 1; i >= 0; i--) {

        int difference = ((number_1[i + difference_dlugosci] - '0') - (number_2[i] - '0') - tmp);

        if (difference < 0) {
            difference = difference + 10;
            tmp = 1;
        }
        else
            tmp = 0;

        result.push_back(difference + '0');
    }

    for (int i = length_1 - length_2 - 1; i >= 0; i--) {
        if (number_1[i] == '0' && tmp) {
            result.push_back('9');
            continue;
        }
        int difference = ((number_1[i] - '0') - tmp);
        if (i > 0 || difference > 0)
            result.push_back(difference + '0');
        tmp = 0;
    }

    for(int i = result.length(); i > 0 ; i--){
        if (result[i-1] == '0'){
            result.pop_back();
        }
        else{
          break;
        }
    }

    if(character == "-"){
        result.push_back('-');

    }

    if(result.length()==0){
        result = '0';
    }
    else{
        reverse(result.begin(), result.end());
    }
    cout << result << endl;
}

void multiplication(string number_1, string number_2, string character)
{
    int length_1 = number_1.size();
    int length_2 = number_2.size();

    std::vector<int> result(length_1 + length_2, 0);

    int length_1_pos = 0;
    int length_2_pos = 0;

    for (int i=length_1-1; i>=0; i--){

        int tmp = 0;
        int length_1 = number_1[i] - '0';

        length_2_pos = 0;

        for (int j=length_2-1; j>=0; j--)
        {

            int length_2 = number_2[j] - '0';
            int sum = length_1*length_2 + result[length_1_pos + length_2_pos] + tmp;
            tmp = sum/10;

            result[length_1_pos + length_2_pos] = sum % 10;
            length_2_pos++;
        }


        if (tmp > 0)
            result[length_1_pos + length_2_pos] += tmp;

        length_1_pos++;
    }

    int i = result.size() - 1;
    while (i>=0 && result[i] == 0)
        i--;

    if (i == -1){
        string output = "0";
        cout <<  output << endl;
    }

    else{
        string output = "";


    if(character == "-"){
        output = "-";
    }

    else{
        output = "";
    }

    while (i >= 0)
        output += std::to_string(result[i--]);

    cout <<  output << endl;

    }
}

string remove_zeros(string number){
	long int i;

	for(i=0;i<number.length();i++){
		if(number.at(i)>48) break;
	}

	if(i==number.length()){
        return "0";
	}

	number.erase(0,i);

	return number;
}

 int number_size(string number_1,string number_2){
	if(number_1.length()>number_2.length()){
        return 1;
	}
	if(number_1.length()<number_2.length()){
        return -1;
	}

	long int i;

	for(i=0;i<number_1.length();i++){
		if(number_1.at(i)>number_2.at(i)) return 1;
		if(number_1.at(i)<number_2.at(i)) return -1;
	}
	return 0;
}
 string substract_division(string number_1,string number_2){

	number_1=remove_zeros(number_1);
	number_2=remove_zeros(number_2);

	long int i,i2=0;

	string tmp="0";
	string tmp1, tmp2;
	string tmp3="-";

	if(number_size(number_1,number_2)==0){
        return tmp;
	}

	if(number_size(number_1,number_2)==1){
		tmp1=number_1;
		tmp2=number_2;
	}

	if(number_size(number_1,number_2)==-1){
		tmp1=number_2;
		tmp2=number_1;
		i2=-1;
	}

	reverse(tmp1.begin(),tmp1.end());
	reverse(tmp2.begin(),tmp2.end());

	for(i=0;i<tmp2.length();i++){
		if(tmp2.at(i)>=48&&tmp2.at(i)<=57) tmp2.at(i)-=48;
		if(tmp2.at(i)>=97&&tmp2.at(i)<=122) tmp2.at(i)-=87;
	}

	for(i=0;i<tmp1.length();i++){
		if(tmp1.at(i)>=48&&tmp1.at(i)<=57) tmp1.at(i)-=48;
		if(tmp1.at(i)>=97&&tmp1.at(i)<=122) tmp1.at(i)-=87;
	}

	for(i=0;i<tmp2.length();i++){
		tmp1.at(i)=tmp1.at(i)-tmp2.at(i);
	}

	for(i=0;i<tmp1.length()-1;i++){
		if(tmp1.at(i)<0)
		{
			tmp1.at(i)+=10;
			tmp1.at(i+1)--;
		}
	}

	for(i=tmp1.length()-1;i>=0;i--){
		if(tmp1.at(i)>0) break;
	}

	tmp1.erase(i+1,tmp1.length());

	for(i=0;i<tmp1.length();i++){
		if(tmp1.at(i)>=10) tmp1.at(i)+=87;
		if(tmp1.at(i)<10) tmp1.at(i)+=48;
	}

	reverse(tmp1.begin(),tmp1.end());

	if(i2==-1){
        tmp1.insert(0,tmp3);
	}

	return tmp1;
}

void division(string number_1,string number_2, string character){

	long int i,j;
	string tmp1,tmp2,tmp3,result;
	if(number_size(number_1,number_2)==0){
        cout << "1" << endl;
    }
	else if(number_size(number_1,number_2)==-1){
		cout << "0" << endl;
	}

	else{
        tmp1=remove_zeros(number_1);
        tmp2=remove_zeros(number_2);
        tmp3="";
        result="";

        for(i=0;i<tmp1.length();i++){
            j=0;
            tmp3=tmp3+tmp1.at(i);
            tmp3=remove_zeros(tmp3);

            while(number_size(tmp3,number_2)>=0){
                 tmp3=substract_division(tmp3,number_2);
                tmp3=remove_zeros(tmp3);
                j++;
            }
            result=result+"0";
            result.at(i)=j;
        }
        for(i=0;i<result.length();i++){
            if(result.at(i)>=10) result.at(i)+=87;
            if(result.at(i)<10) result.at(i)+=48;
        }
        result=remove_zeros(result);

        if(character == "-"){
            reverse(result.begin(), result.end());
            result.push_back('-');
            reverse(result.begin(), result.end());

        }

	cout << result << endl;

    }
}

struct ret {
    int position;
    char oper;
};

typedef struct ret Struct;

Struct is_operation(string line){
    Struct ret;

    if(line.find('+') != string::npos){
        ret.position = line.find('+');
        ret.oper = '+';

        return ret;
    }

    else if(line.find("*") != string::npos){
        ret.position = line.find('*');
        ret.oper = '*';
        return ret;
    }

    else if(line.find("/") != string::npos){
        ret.position = line.find('/');
        ret.oper = '/';
        return ret;
    }

    else if(line.find("-") != string::npos){
        ret.position = line.find('-');
        ret.oper = '-';

        if (ret.position == 0){
            ret.position = line.find('-',1);
        }
        return ret;
    }

    else{
        ret.position = 0;
        ret.oper = NULL;
        return ret;
    }

}

int main()
{
    string line, tab[256];
    string number[2], operacja;
    string character[2];
    Struct result;
    char inp;
    int counter=0, Z=0;

    while (getline(cin, line)){
        result = is_operation(line);

        if(result.position == 0){
            counter = 0;
            Z = stoi(line);
        }
        else{

            number[0] = "";
            number[1] = "";

            if(line[0] == '-'){
                character[0] = '-';

                for(int i=1; i < result.position; i++){
                    number[0] += line[i];
                }
            }
            else{
                character[0] = '+';

                for(int i=0; i < result.position; i++){
                    number[0] += line[i];
                }

            }

            if(line[result.position+1] == '-'){
                character[1] = '-';

                for(int i=result.position+2; i < line.length(); i++){
                    number[1] += line[i];
                }
            }
            else{
                character[1] = '+';
                for(int i=result.position+1; i < line.length(); i++){
                    number[1] += line[i];
                }
            }

            if (result.oper == '+'){

                if((character[0] == "+") && (character[1] == "+")){
                    addtion(number[0], number[1]);
                }

                else if(character[0] == "-" && character[1] == "-"){
                    addtion(number[0], number[1], "-");
                }

                else if(character[0] == "-" && character[1] == "+"){
                    substraction(number[1], number[0]);
                }

                else if(character[0] == "+" && character[1] == "-"){
                    substraction(number[0], number[1]);
                }


            }

            else if (result.oper == '-'){

                if((character[0] == "+") && (character[1] == "+")){
                    substraction(number[0], number[1]);
                }

                else if(character[0] == "-" && character[1] == "-"){
                    substraction(number[1], number[0]);
                }

                else if(character[0] == "-" && character[1] == "+"){
                    addtion(number[0], number[1], "-");
                }

                else if(character[0] == "+" && character[1] == "-"){
                    addtion(number[0], number[1]);
                }
            }

            else if (result.oper == '*'){

                if((character[0] == "+") && (character[1] == "+")){
                    multiplication(number[0], number[1], "+");
                }

                else if(character[0] == "-" && character[1] == "-"){
                    multiplication(number[0], number[1], "+");
                }

                else if(character[0] == "-" && character[1] == "+"){
                    multiplication(number[0], number[1], "-");
                }

                else if(character[0] == "+" && character[1] == "-"){
                    multiplication(number[0], number[1], "-");
                }

            }
            else if (result.oper == '/'){
                if(number[1] != "0"){

                    if((character[0] == "+") && (character[1] == "+")){
                        division(number[0], number[1], "+");
                    }

                    else if(character[0] == "-" && character[1] == "-"){
                        division(number[0], number[1], "+");
                    }

                    else if(character[0] == "-" && character[1] == "+"){
                        division(number[0], number[1], "-");
                    }

                    else if(character[0] == "+" && character[1] == "-"){
                        division(number[0], number[1], "-");
                    }
                else{
                    continue;
                }
                }
            }

            counter += 1;

            if (counter == Z){
                break;
            }

        }

    }

    return 0;
}


