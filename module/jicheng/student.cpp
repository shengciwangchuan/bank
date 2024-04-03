class human {
public:
	string name = "小明";
};
class student:public human {
public:
	string name = "小红";
	void print()
	{
		cout << name << endl;
	}
};
int main()
{
	student st;
	st.print();
	return 0;
}