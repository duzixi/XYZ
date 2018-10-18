#include "stdafx.h"
#include "ZXDataFile.h"

string formats[] = {  // 【注意】：该顺序要与枚举定义一致，否则返回出错。添加类型时位置要一致
	"TXT", // x,y,z  自己约定的，如果不指定，则按这个类型输出
	"OFF",
	"PCD", 
	"PLY",
	"PTS", // x y z
	"XYZ", // x y z
	"OBJ", // v x y z
	"STL" // vertex x y z
};

ZXDataFile::ZXDataFile(void)
{
}


ZXDataFile::~ZXDataFile(void)
{
}

// 【接口】数据转换
bool ZXDataFile::Convert(char *inputFileName, DataFormat outFormat)
{

	// STEP 0 输入输出文件名及格式
	DataFormat inFormat = GetFormatByFileName(inputFileName);
	string inSeperator = inFormat == F_TXT ? "," : " ";

	stringstream ss;
	ss << inputFileName << "." << formats[outFormat];

	// STEP 1 同时打开输入输出文件
	ifstream ifile; // 输入文件
	ifile.open(inputFileName, ios::in);
	if (!ifile.is_open())
	{
		cout << "Error: 打开输入文件 " << inputFileName << "错误" << endl; 
		return false;
	}
	// 以下先考虑TXT -> XYZ【未完待续】
	int iX, iY, iZ;
	switch (inFormat)
	{
	case F_TXT:
	case F_OFF:
	case F_PCD:
	case F_PLY:
	case F_PTS:
	case F_XYZ:
		iX = 0;
		iY = 1;
		iZ = 2;
		break;
	case F_OBJ:
	case F_STL:
		iX = 1;
		iY = 2;
		iZ = 3;
		break;
	default:
		iX = 0;
		iY = 1;
		iZ = 2;
		break;
	}

	ofstream ofile;
	ofile.open(ss.str().c_str(), ios::out);
	if (!ofile.is_open())
	{
		cout << "Error：打开输出文件 " << ss << " 错误" << endl;
		return false;
	}
	string outSeperator = outFormat == F_TXT ? "," : " ";

	// STEP 2 开始读一行写一行的循环
	int lineNum = 0;  // 文件总行数
	char buffer[256];
	while (!ifile.eof())
	{
		if (lineNum % 10000 == 0)
		{
			cout << lineNum << endl;  // 每1万点输出一下进度
		}
		// STEP 2.1 先读 -------------------------------

		// 文件头的解析与处理【未完待续】

		// 先读进来,按分隔符切割
		ifile.getline(buffer, 256);
		string line = string(buffer);
		vector<string> numStr = ZXTool::split(line, inSeperator);

		if (numStr.size() > iZ)
		{
			float x = atof(numStr[iX].c_str());
			float y = atof(numStr[iY].c_str());
			float z = atof(numStr[iZ].c_str());

			// STEP 2.2 再写 -------------------------------

			// 文件头的生成与处理【未完待续】

			// 写入数据
			if (outFormat == F_STL)
			{
				ofile << "vertex ";
			}
			stringstream xyz;
			xyz  << x << outSeperator << y << outSeperator << z << endl;

			ofile << xyz ;

			lineNum++;
		}
	}

	// 写入其它数据...... 这个怎么搞 线和面还得生成？？？

	// STEP 3 关闭文件
	ifile.close();
	ofile.close();

	return true; // 转换成功
}


// 根据文件扩展名，判断文件类型
DataFormat ZXDataFile::GetFormatByFileName(char *fileName)
{

	string name = string(fileName);
	vector<string> str = split(name, ".");
	string extension = str[str.size() - 1];

	transform(extension.begin(), extension.end(), extension.begin(), toupper);

	for (int i = 0; i < 10; i++)
	{
		if (formats[i] == extension)
		{
			return (DataFormat) i;
		}
	}

	return F_TXT;
}

vector<string> split(const string &s, const string &seperator) {
	size_t last = 0;
	size_t index = s.find_first_of(seperator);
	vector<string> result;

	while (index != string::npos)
	{
		result.push_back(s.substr(last, index-last));
		last = index + 1;
		index = s.find_first_of(seperator, last);
	}

	if (index-last>0)
	{
		result.push_back(s.substr(last, index-last));
	}
	return result;

}