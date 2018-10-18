// ================================================================
//  ZXDataFile.h
//  功能定位：点云数据文件格式转换
//  根据点云文件格式名，点云数据结构，判断格式类型，进而转换为目标格式
// ----------------------------------------------------------------
//  Created by 杜子兮 on 2018.8.2
// ================================================================

#pragma once

enum DataFormat
{
	// 以下均为文本格式
	F_TXT, // x,y,z  自己约定的，如果不指定，则按这个类型输出
	F_OFF, // x y z
	F_PCD, // x y z
	F_PLY, // x y z
	F_PTS, // x y z
	F_XYZ, // x y z
	F_OBJ, // v x y z
	F_STL // vertex x y z
};

class ZXDataFile
{
public:
	ZXDataFile(void);
	~ZXDataFile(void);

	// 数据转换
	// 提取点云
	static bool Convert(char *inputFileName, DataFormat format);

private:
	// 根据文件扩展名，判断文件类型
	static DataFormat GetFormatByFileName(char *fileName);
};

