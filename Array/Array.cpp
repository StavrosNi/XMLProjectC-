// Array.cpp : Defines the entry point for the console application.
//
#define _CRT_SECURE_NO_WARNINGS
#include "stdafx.h"
#include <iostream>
#include "tinyxml.h"
#include "tinystr.h"
#include <vector>
#include <iterator>
#include <sstream>
#include <fstream>
#include <ctime>
#include <chrono> 
#include <vector>
using namespace std;

/*
int *function() {

	int *p = new int[5];
	for (int i = 0; i < 5; i++) {
		p[i] = i;
		cout << p[i] <<" " ;
		
	}
	return p;
	delete[]p;
	
}*/


struct day
{
	std::string name;
	std::string note;
};

struct test {
	std::string element3;
};

vector<test> customTest;
/*
struct tpassed {
	string testPass;
};

struct meastype {
	string measureType;
};

struct failDes {
	string failreason;
};
*/
int forCount = 0; 
vector<string> testpassed;
vector<string> measureType;
vector <string> failDescription;

//struct meastype measureType[12];
//struct tpassed TstPassed[12];
struct test TestArray[16];
//struct failDes failDescription[12];

void SaveToXML(test testArray[]) {


	TiXmlDocument doc;
	TiXmlDeclaration * decl = new TiXmlDeclaration("1.0", "utf-8", "");
	//	doc.FirstChildElement();
	doc.LinkEndChild(decl);

	TiXmlElement *rootelement = new TiXmlElement("TestData");
	doc.LinkEndChild(rootelement);

	TiXmlElement *Operator = new TiXmlElement("Operator"); //Tree root
	rootelement->LinkEndChild(Operator);

	TiXmlText *textOperator = new TiXmlText("Alex");
	Operator->LinkEndChild(textOperator);

	TiXmlElement *barcode = new TiXmlElement("ParentBarCode"); //Tree root
	rootelement->LinkEndChild(barcode);

	TiXmlText *textbarcode = new TiXmlText("01268");
	barcode->LinkEndChild(textbarcode);

	TiXmlElement *root = new TiXmlElement("Measurements"); //Tree root
	rootelement->LinkEndChild(root);

	TiXmlText *textMeasure = new TiXmlText("");
	root->LinkEndChild(textMeasure);

	for (int i = 0; i <4; i++) {

		TiXmlElement *element = new TiXmlElement("Measurement"); //Tree root
		root->LinkEndChild(element);

		//	char chartests[] = TestManagerPtr->getTestsRunning().length;
		//strcpy(chartests, TestManagerPtr->getTestsRunning().c_str());
		//std::string testStatus = to_string(lTestNumber) + "passed ";
		//char const *testStat = testStatus.c_str();
		TiXmlText *textbarcode = new TiXmlText("");
		element->LinkEndChild(textbarcode);

		TiXmlElement *element2 = new TiXmlElement("Name"); //Tree root
		element->LinkEndChild(element2);

		//	TiXmlText *text2 = new TiXmlText(("Test" + to_string(lSuiteTxIndex) + " CAN Extended").c_str());
		TiXmlText *text2 = new TiXmlText(("Test" + to_string(i)).c_str());
		element2->LinkEndChild(text2);

		TiXmlElement *element3 = new TiXmlElement("Url");
		element->LinkEndChild(element3);
		
		TiXmlText *text3 = new TiXmlText(TestArray[i].element3.c_str());
		element3->LinkEndChild(text3);

		TiXmlElement *element4 = new TiXmlElement("Sequence");
		element->LinkEndChild(element4);

		TiXmlText *text4 = new TiXmlText(to_string(i).c_str());
		element4->LinkEndChild(text4);

		TiXmlElement *element5 = new TiXmlElement("MeasurementType");
		element->LinkEndChild(element5);
		//rootelement->LastChild()->InsertAfterChild(element4,element5);

	//	struct meastype {
	//		string measureType;
		//};

		//Declaration of Measurement type description
		measureType.push_back("Test1:Establishing CAN 0 network");
		measureType.push_back("Test2:CAN 0 Clear DTCs");
		measureType.push_back("Test3:Checks if the Tuner 3 Background scanning is working");
		measureType.push_back("Test4:Checks if PCB revisions are written on device EEPROM");
		measureType.push_back("Test5:Checks if the H/W Part Number is written on device EEPROM");
		measureType.push_back("Test6:Checks to see if Modem is present");
		measureType.push_back("Test7:SIM card present check");
		measureType.push_back("Test8: SIM card data connection check");
		measureType.push_back("Test9: SIM card ID check");
		measureType.push_back("Test10: GPS Check to see if Ublox is linked to a Satelite");
		measureType.push_back("Test11: WiFi connectivity check");
		measureType.push_back("Test12: Checks to see if Broad-R Reach is working");
		measureType.push_back("Test13: WiFi MAC address check");
		measureType.push_back("Test14: Broad-R MAC address check");
		measureType.push_back("Test15: Checks if USB port2/port3 are working");
		measureType.push_back("Test16: SPBC LIN connection check");

		TiXmlText *text5 = new TiXmlText(measureType[i].c_str());
		element5->LinkEndChild(text5);

		//	TiXmlText *text5 = new TiXmlText("automatic");
		//	element5->LinkEndChild(text5);

		TiXmlElement *element6 = new TiXmlElement("Result");
		element->LinkEndChild(element6);

		testpassed.push_back("PASSED"); //test1
		testpassed.push_back("PASSED"); //test2
		testpassed.push_back("PASSED"); //test3
		testpassed.push_back("PASSED"); //test4
		testpassed.push_back("PASSED"); //test5
		testpassed.push_back("PASSED"); //test6
		testpassed.push_back("PASSED"); //test7
		testpassed.push_back("PASSED"); //test8
		testpassed.push_back("PASSED"); //test9
		testpassed.push_back("FAILED"); //test10
		testpassed.push_back("FAILED"); //test11
		testpassed.push_back("PASSED"); //test12
		testpassed.push_back("FAILED"); //test13
		testpassed.push_back("FAILED"); //test14
		testpassed.push_back("PASSED"); //test15
		testpassed.push_back("FAILED"); //test16

   /*	TstPassed[1].testPass = "PASSED";
	   TstPassed[2].testPass = "FAILED";
	   TstPassed[3].testPass = "PASSED";
	   TstPassed[4].testPass = "PASSED";
	   TstPassed[5].testPass = "PASSED";
	   TstPassed[6].testPass = "PASSED";
	   TstPassed[7].testPass = "PASSED";
	   TstPassed[8].testPass = "PASSED";
	   TstPassed[9].testPass = "PASSED";
	   TstPassed[10].testPass = "PASSED";
	   TstPassed[11].testPass = "FAILED"; */

		TiXmlText *text6 = new TiXmlText(testpassed.at(i).c_str());
		element6->LinkEndChild(text6);

		TiXmlElement *element7 = new TiXmlElement("Value");
		element->LinkEndChild(element7);

		TiXmlText *text7 = new TiXmlText("");
		element7->LinkEndChild(text7);

		TiXmlElement *element8 = new TiXmlElement("Units");
		element->LinkEndChild(element8);

		TiXmlText *text8 = new TiXmlText("");
		element8->LinkEndChild(text8);

		TiXmlElement *element9 = new TiXmlElement("Nominal");
		element->LinkEndChild(element9);

		TiXmlText *text9 = new TiXmlText("");
		element9->LinkEndChild(text9);

		TiXmlElement *element10 = new TiXmlElement("LowerLimit");
		element->LinkEndChild(element10);

		TiXmlText *text10 = new TiXmlText("");
		element10->LinkEndChild(text10);

		TiXmlElement *element11 = new TiXmlElement("UpperLimit");
		element->LinkEndChild(element11);

		TiXmlText *text11 = new TiXmlText("");
		element11->LinkEndChild(text11);

		TiXmlElement *element12 = new TiXmlElement("FailDesc");
		element->LinkEndChild(element12);

		//Creating Faildescription's description in struct used
		if (testpassed[0] == "FAILED") {
			failDescription.push_back ("Unable to establish CAN0");
		}
		else
			failDescription.push_back("");

		if (testpassed.at(1) == "FAILED") {
			failDescription.push_back ("Unable to clear DTCs");
		}
		else failDescription.push_back("");

		if (testpassed.at(2) == "FAILED") {
			failDescription.push_back( "Unable to scan for stations");
		}
		else failDescription.push_back("");

		if (testpassed.at(3) == "FAILED") {
			failDescription.push_back("Unable to read from Titan");
		}
		else failDescription.push_back("");

		if (testpassed.at(4) == "FAILED") {
			failDescription.push_back ("Unable to read from Titan/EEPROM");
		}
		else failDescription.push_back("");

		if (testpassed.at(5) == "FAILED") {
			failDescription.push_back( "Unable to enumerate modem");
		}
		else failDescription.push_back("");

		if (testpassed.at(6) == "FAILED") {
			failDescription.push_back("Unable to see SIM Card, Please Check presence of SIM Card");
		}
		else failDescription.push_back("");

		if (testpassed.at(7) == "FAILED") {
			failDescription.push_back( "Unable to see SIM Card, or Modem");
		}
		else failDescription.push_back("");

		if (testpassed.at(8) == "FAILED") {
			failDescription.push_back("Unable to see SIM Card, or Modem not Functioning");
		}
		else failDescription.push_back("");

		if (testpassed.at(9) == "FAILED") {
			failDescription.push_back( "Unable to get GPS Fix, Check Ublox or Antenna");
		}
		else failDescription.push_back("");

		if (testpassed.at(10) == "FAILED") {
			failDescription.push_back( "Unable to establish WiFi connection");
		}
		else failDescription.push_back("");

		if (testpassed.at(11) == "FAILED") {
					failDescription.push_back ("Unable to connect to Broad-R Reach");
		}
		else failDescription.push_back("");

		if (testpassed.at(12) == "FAILED") {
					failDescription.push_back ( "WiFi Mac Address is not correct");
		}
		else failDescription.push_back("");

		if (testpassed.at(13) == "FAILED") {
					failDescription.push_back( "Broad-R MAC address not correct");
		}
		else failDescription.push_back("");

		if (testpassed.at(14) == "FAILED") {
					failDescription.push_back("USB ports 2/3 not working");
		}
		else failDescription.push_back("");

		if (testpassed.at(15) == "FAILED") {
					failDescription.push_back("Unable to establish SPBC LIN connection");
		}
		else failDescription.push_back("");

				
		//end of fail declarations
		TiXmlText *text12 = new TiXmlText(failDescription.at(i).c_str());
		element12->LinkEndChild(text12);

		TiXmlElement *element13 = new TiXmlElement("DateAndTime");
		element->LinkEndChild(element13);

		std::time_t rawtime;
		std::tm* timeinfo;
		char buffer[80];

		std::time(&rawtime);
		timeinfo = std::localtime(&rawtime);

		std::strftime(buffer, 80, "%Y-%m-%d %H-%M-%S", timeinfo);
		std::puts(buffer);
		std::string time(buffer);
		std::cout << time;

		TiXmlText *text13 = new TiXmlText(time.c_str());
		element13->LinkEndChild(text13);

		while (!doc.SaveFile("C:\\Users\\ge040\\Documents\\Visual Studio 2015\\Projects\\Array\\Array.xml"))
		{
			cout << "Unable to create file" << endl;
			exit(2);
			
		}

		cout << "File saved successfully" << endl;
	//	system("pause");
		forCount++;
		
	
	}

	//Creating element 5


	for (int i = 4; i <5; i++) {

		TiXmlElement *element = new TiXmlElement("Measurement"); //Tree root
		root->LinkEndChild(element);

		//	char chartests[] = TestManagerPtr->getTestsRunning().length;
		//strcpy(chartests, TestManagerPtr->getTestsRunning().c_str());
		//std::string testStatus = to_string(lTestNumber) + "passed ";
		//char const *testStat = testStatus.c_str();
		TiXmlText *textbarcode = new TiXmlText("");
		element->LinkEndChild(textbarcode);

		TiXmlElement *element2 = new TiXmlElement("Name"); //Tree root
		element->LinkEndChild(element2);

		//	TiXmlText *text2 = new TiXmlText(("Test" + to_string(lSuiteTxIndex) + " CAN Extended").c_str());
		TiXmlText *text2 = new TiXmlText(("Test" + to_string(i)).c_str());
		element2->LinkEndChild(text2);

		TiXmlElement *element3 = new TiXmlElement("Url");
		element->LinkEndChild(element3);

		TiXmlText *text3 = new TiXmlText(TestArray[i].element3.c_str());
		element3->LinkEndChild(text3);

		TiXmlElement *element4 = new TiXmlElement("Sequence");
		element->LinkEndChild(element4);

		TiXmlText *text4 = new TiXmlText(to_string(i).c_str());
		element4->LinkEndChild(text4);

		TiXmlElement *element5 = new TiXmlElement("MeasurementType");
		element->LinkEndChild(element5);
		//rootelement->LastChild()->InsertAfterChild(element4,element5);

		//	struct meastype {
		//		string measureType;
		//};

		//Declaration of Measurement type description
		measureType.push_back("Test1:Establishing CAN 0 network");
		measureType.push_back("Test2:CAN 0 Clear DTCs");
		measureType.push_back("Test3:Checks if the Tuner 3 Background scanning is working");
		measureType.push_back("Test4:Checks if PCB revisions are written on device EEPROM");
		measureType.push_back("Test5:Checks if the H/W Part Number is written on device EEPROM");
		measureType.push_back("Test6:Checks to see if Modem is present");
		measureType.push_back("Test7:SIM card present check");
		measureType.push_back("Test8: SIM card data connection check");
		measureType.push_back("Test9: SIM card ID check");
		measureType.push_back("Test10: GPS Check to see if Ublox is linked to a Satelite");
		measureType.push_back("Test11: WiFi connectivity check");
		measureType.push_back("Test12: Checks to see if Broad-R Reach is working");
		measureType.push_back("Test13: WiFi MAC address check");
		measureType.push_back("Test14: Broad-R MAC address check");
		measureType.push_back("Test15: Checks if USB port2/port3 are working");
		measureType.push_back("Test16: SPBC LIN connection check");

		TiXmlText *text5 = new TiXmlText(measureType[i].c_str());
		element5->LinkEndChild(text5);

		//	TiXmlText *text5 = new TiXmlText("automatic");
		//	element5->LinkEndChild(text5);

		TiXmlElement *element6 = new TiXmlElement("Result");
		element->LinkEndChild(element6);

		testpassed.push_back("PASSED"); //test1
		testpassed.push_back("PASSED"); //test2
		testpassed.push_back("PASSED"); //test3
		testpassed.push_back("PASSED"); //test4
		testpassed.push_back("PASSED"); //test5
		testpassed.push_back("PASSED"); //test6
		testpassed.push_back("PASSED"); //test7
		testpassed.push_back("PASSED"); //test8
		testpassed.push_back("PASSED"); //test9
		testpassed.push_back("FAILED"); //test10
		testpassed.push_back("FAILED"); //test11
		testpassed.push_back("PASSED"); //test12
		testpassed.push_back("FAILED"); //test13
		testpassed.push_back("FAILED"); //test14
		testpassed.push_back("PASSED"); //test15
		testpassed.push_back("FAILED"); //test16

				
		TiXmlText *text6 = new TiXmlText(testpassed.at(i).c_str());
		element6->LinkEndChild(text6);

		TiXmlElement *element7 = new TiXmlElement("Value");
		element->LinkEndChild(element7);

		TiXmlText *text7 = new TiXmlText("066-0345-B0");
		element7->LinkEndChild(text7);

		TiXmlElement *element8 = new TiXmlElement("Units");
		element->LinkEndChild(element8);

		TiXmlText *text8 = new TiXmlText("");
		element8->LinkEndChild(text8);

		TiXmlElement *element9 = new TiXmlElement("Nominal");
		element->LinkEndChild(element9);

		TiXmlText *text9 = new TiXmlText("");
		element9->LinkEndChild(text9);

		TiXmlElement *element10 = new TiXmlElement("LowerLimit");
		element->LinkEndChild(element10);

		TiXmlText *text10 = new TiXmlText("");
		element10->LinkEndChild(text10);

		TiXmlElement *element11 = new TiXmlElement("UpperLimit");
		element->LinkEndChild(element11);

		TiXmlText *text11 = new TiXmlText("");
		element11->LinkEndChild(text11);

		TiXmlElement *element12 = new TiXmlElement("FailDesc");
		element->LinkEndChild(element12);

		//Creating Faildescription's description in struct used
		if (testpassed[0] == "FAILED") {
			failDescription.push_back("Unable to establish CAN0");
		}
		else
			failDescription.push_back("");

		if (testpassed.at(1) == "FAILED") {
			failDescription.push_back("Unable to clear DTCs");
		}
		else failDescription.push_back("");

		if (testpassed.at(2) == "FAILED") {
			failDescription.push_back("Unable to scan for stations");
		}
		else failDescription.push_back("");

		if (testpassed.at(3) == "FAILED") {
			failDescription.push_back("Unable to read from Titan");
		}
		else failDescription.push_back("");

		if (testpassed.at(4) == "FAILED") {
			failDescription.push_back("Unable to read from Titan/EEPROM");
		}
		else failDescription.push_back("");

		if (testpassed.at(5) == "FAILED") {
			failDescription.push_back("Unable to enumerate modem");
		}
		else failDescription.push_back("");

		if (testpassed.at(6) == "FAILED") {
			failDescription.push_back("Unable to see SIM Card, Please Check presence of SIM Card");
		}
		else failDescription.push_back("");

		if (testpassed.at(7) == "FAILED") {
			failDescription.push_back("Unable to see SIM Card, or Modem");
		}
		else failDescription.push_back("");

		if (testpassed.at(8) == "FAILED") {
			failDescription.push_back("Unable to see SIM Card, or Modem not Functioning");
		}
		else failDescription.push_back("");

		if (testpassed.at(9) == "FAILED") {
			failDescription.push_back("Unable to get GPS Fix, Check Ublox or Antenna");
		}
		else failDescription.push_back("");

		if (testpassed.at(10) == "FAILED") {
			failDescription.push_back("Unable to establish WiFi connection");
		}
		else failDescription.push_back("");

		if (testpassed.at(11) == "FAILED") {
			failDescription.push_back("Unable to connect to Broad-R Reach");
		}
		else failDescription.push_back("");

		if (testpassed.at(12) == "FAILED") {
			failDescription.push_back("WiFi Mac Address is not correct");
		}
		else failDescription.push_back("");

		if (testpassed.at(13) == "FAILED") {
			failDescription.push_back("Broad-R MAC address not correct");
		}
		else failDescription.push_back("");

		if (testpassed.at(14) == "FAILED") {
			failDescription.push_back("USB ports 2/3 not working");
		}
		else failDescription.push_back("");

		if (testpassed.at(15) == "FAILED") {
			failDescription.push_back("Unable to establish SPBC LIN connection");
		}
		else failDescription.push_back("");


		//end of fail declarations
		TiXmlText *text12 = new TiXmlText(failDescription.at(i).c_str());
		element12->LinkEndChild(text12);

		TiXmlElement *element13 = new TiXmlElement("DateAndTime");
		element->LinkEndChild(element13);

		std::time_t rawtime;
		std::tm* timeinfo;
		char buffer[80];

		std::time(&rawtime);
		timeinfo = std::localtime(&rawtime);

		std::strftime(buffer, 80, "%Y-%m-%d %H-%M-%S", timeinfo);
		std::puts(buffer);
		std::string time(buffer);
		std::cout << time;

		TiXmlText *text13 = new TiXmlText(time.c_str());
		element13->LinkEndChild(text13);

		while (!doc.SaveFile("C:\\Users\\ge040\\Documents\\Visual Studio 2015\\Projects\\Array\\Array.xml"))
		{
			cout << "Unable to create file" << endl;
			exit(2);

		}

		cout << "File saved successfully" << endl;
		//	system("pause");
		forCount++;


	}

	//Creating elements 6 to 16
	for (int i = 5; i <16; i++) {

		TiXmlElement *element = new TiXmlElement("Measurement"); //Tree root
		root->LinkEndChild(element);

		//	char chartests[] = TestManagerPtr->getTestsRunning().length;
		//strcpy(chartests, TestManagerPtr->getTestsRunning().c_str());
		//std::string testStatus = to_string(lTestNumber) + "passed ";
		//char const *testStat = testStatus.c_str();
		TiXmlText *textbarcode = new TiXmlText("");
		element->LinkEndChild(textbarcode);

		TiXmlElement *element2 = new TiXmlElement("Name"); //Tree root
		element->LinkEndChild(element2);

		//	TiXmlText *text2 = new TiXmlText(("Test" + to_string(lSuiteTxIndex) + " CAN Extended").c_str());
		TiXmlText *text2 = new TiXmlText(("Test"+ to_string(i)).c_str());
		element2->LinkEndChild(text2);

		TiXmlElement *element3 = new TiXmlElement("Url");
		element->LinkEndChild(element3);

		TiXmlText *text3 = new TiXmlText(TestArray[i].element3.c_str());
		element3->LinkEndChild(text3);

		TiXmlElement *element4 = new TiXmlElement("Sequence");
		element->LinkEndChild(element4);

		TiXmlText *text4 = new TiXmlText(to_string(i).c_str());
		element4->LinkEndChild(text4);

		TiXmlElement *element5 = new TiXmlElement("MeasurementType");
		element->LinkEndChild(element5);
		//rootelement->LastChild()->InsertAfterChild(element4,element5);

		//	struct meastype {
		//		string measureType;
		//};

		//Declaration of Measurement type description
		measureType.push_back("Test1:Establishing CAN 0 network");
		measureType.push_back("Test2:CAN 0 Clear DTCs");
		measureType.push_back("Test3:Checks if the Tuner 3 Background scanning is working");
		measureType.push_back("Test4:Checks if PCB revisions are written on device EEPROM");
		measureType.push_back("Test5:Checks if the H/W Part Number is written on device EEPROM");
		measureType.push_back("Test6:Checks to see if Modem is present");
		measureType.push_back("Test7:SIM card present check");
		measureType.push_back("Test8: SIM card data connection check");
		measureType.push_back("Test9: SIM card ID check");
		measureType.push_back("Test10: GPS Check to see if Ublox is linked to a Satelite");
		measureType.push_back("Test11: WiFi connectivity check");
		measureType.push_back("Test12: Checks to see if Broad-R Reach is working");
		measureType.push_back("Test13: WiFi MAC address check");
		measureType.push_back("Test14: Broad-R MAC address check");
		measureType.push_back("Test15: Checks if USB port2/port3 are working");
		measureType.push_back("Test16: SPBC LIN connection check");

		TiXmlText *text5 = new TiXmlText(measureType[i].c_str());
		element5->LinkEndChild(text5);

		//	TiXmlText *text5 = new TiXmlText("automatic");
		//	element5->LinkEndChild(text5);

		TiXmlElement *element6 = new TiXmlElement("Result");
		element->LinkEndChild(element6);

		testpassed.push_back("PASSED"); //test1
		testpassed.push_back("PASSED"); //test2
		testpassed.push_back("PASSED"); //test3
		testpassed.push_back("PASSED"); //test4
		testpassed.push_back("PASSED"); //test5
		testpassed.push_back("PASSED"); //test6
		testpassed.push_back("PASSED"); //test7
		testpassed.push_back("PASSED"); //test8
		testpassed.push_back("PASSED"); //test9
		testpassed.push_back("FAILED"); //test10
		testpassed.push_back("FAILED"); //test11
		testpassed.push_back("PASSED"); //test12
		testpassed.push_back("FAILED"); //test13
		testpassed.push_back("FAILED"); //test14
		testpassed.push_back("PASSED"); //test15
		testpassed.push_back("FAILED"); //test16

										/*	TstPassed[1].testPass = "PASSED";
										TstPassed[2].testPass = "FAILED";
										TstPassed[3].testPass = "PASSED";
										TstPassed[4].testPass = "PASSED";
										TstPassed[5].testPass = "PASSED";
										TstPassed[6].testPass = "PASSED";
										TstPassed[7].testPass = "PASSED";
										TstPassed[8].testPass = "PASSED";
										TstPassed[9].testPass = "PASSED";
										TstPassed[10].testPass = "PASSED";
										TstPassed[11].testPass = "FAILED"; */

		TiXmlText *text6 = new TiXmlText(testpassed.at(i).c_str());
		element6->LinkEndChild(text6);

		TiXmlElement *element7 = new TiXmlElement("Value");
		element->LinkEndChild(element7);

		TiXmlText *text7 = new TiXmlText("");
		element7->LinkEndChild(text7);

		TiXmlElement *element8 = new TiXmlElement("Units");
		element->LinkEndChild(element8);

		TiXmlText *text8 = new TiXmlText("");
		element8->LinkEndChild(text8);

		TiXmlElement *element9 = new TiXmlElement("Nominal");
		element->LinkEndChild(element9);

		TiXmlText *text9 = new TiXmlText("");
		element9->LinkEndChild(text9);

		TiXmlElement *element10 = new TiXmlElement("LowerLimit");
		element->LinkEndChild(element10);

		TiXmlText *text10 = new TiXmlText("");
		element10->LinkEndChild(text10);

		TiXmlElement *element11 = new TiXmlElement("UpperLimit");
		element->LinkEndChild(element11);

		TiXmlText *text11 = new TiXmlText("");
		element11->LinkEndChild(text11);

		TiXmlElement *element12 = new TiXmlElement("FailDesc");
		element->LinkEndChild(element12);

		//Creating Faildescription's description in struct used
		if (testpassed[0] == "FAILED") {
			failDescription.push_back("Unable to establish CAN0");
		}
		else
			failDescription.push_back("");

		if (testpassed.at(1) == "FAILED") {
			failDescription.push_back("Unable to clear DTCs");
		}
		else failDescription.push_back("");

		if (testpassed.at(2) == "FAILED") {
			failDescription.push_back("Unable to scan for stations");
		}
		else failDescription.push_back("");

		if (testpassed.at(3) == "FAILED") {
			failDescription.push_back("Unable to read from Titan");
		}
		else failDescription.push_back("");

		if (testpassed.at(4) == "FAILED") {
			failDescription.push_back("Unable to read from Titan/EEPROM");
		}
		else failDescription.push_back("");

		if (testpassed.at(5) == "FAILED") {
			failDescription.push_back("Unable to enumerate modem");
		}
		else failDescription.push_back("");

		if (testpassed.at(6) == "FAILED") {
			failDescription.push_back("Unable to see SIM Card, Please Check presence of SIM Card");
		}
		else failDescription.push_back("");

		if (testpassed.at(7) == "FAILED") {
			failDescription.push_back("Unable to see SIM Card, or Modem");
		}
		else failDescription.push_back("");

		if (testpassed.at(8) == "FAILED") {
			failDescription.push_back("Unable to see SIM Card, or Modem not Functioning");
		}
		else failDescription.push_back("");

		if (testpassed.at(9) == "FAILED") {
			failDescription.push_back("Unable to get GPS Fix, Check Ublox or Antenna");
		}
		else failDescription.push_back("");

		if (testpassed.at(10) == "FAILED") {
			failDescription.push_back("Unable to establish WiFi connection");
		}
		else failDescription.push_back("");

		if (testpassed.at(11) == "FAILED") {
			failDescription.push_back("Unable to connect to Broad-R Reach");
		}
		else failDescription.push_back("");

		if (testpassed.at(12) == "FAILED") {
			failDescription.push_back("WiFi Mac Address is not correct");
		}
		else failDescription.push_back("");

		if (testpassed.at(13) == "FAILED") {
			failDescription.push_back("Broad-R MAC address not correct");
		}
		else failDescription.push_back("");

		if (testpassed.at(14) == "FAILED") {
			failDescription.push_back("USB ports 2/3 not working");
		}
		else failDescription.push_back("");

		if (testpassed.at(15) == "FAILED") {
			failDescription.push_back("Unable to establish SPBC LIN connection");
		}
		else failDescription.push_back("");


		//end of fail declarations
		TiXmlText *text12 = new TiXmlText(failDescription.at(i).c_str());
		element12->LinkEndChild(text12);

		TiXmlElement *element13 = new TiXmlElement("DateAndTime");
		element->LinkEndChild(element13);

		std::time_t rawtime;
		std::tm* timeinfo;
		char buffer[80];

		std::time(&rawtime);
		timeinfo = std::localtime(&rawtime);

		std::strftime(buffer, 80, "%Y-%m-%d %H-%M-%S", timeinfo);
		std::puts(buffer);
		std::string time(buffer);
		std::cout << time;

		TiXmlText *text13 = new TiXmlText(time.c_str());
		element13->LinkEndChild(text13);

		while (!doc.SaveFile("C:\\Users\\ge040\\Documents\\Visual Studio 2015\\Projects\\Array\\Array.xml"))
		{
			cout << "Unable to create file" << endl;
			exit(2);

		}

		cout << "File saved successfully" << endl;
		//	system("pause");
		forCount++;


	}



}
	


/*
void write_simple_doc3()
{
	// This example courtesy of polocolege

	TiXmlDocument doc;
	TiXmlDeclaration * decl = new TiXmlDeclaration("1.0", "", "");
	doc.LinkEndChild(decl);

	TiXmlElement * element = new TiXmlElement("Hello");
	doc.LinkEndChild(element);

	TiXmlText * text = new TiXmlText("Opening a new salutation");
	element->LinkEndChild(text);

	TiXmlElement * element2 = new TiXmlElement("Greeting");
	element->LinkEndChild(element2);

	TiXmlText * text2 = new TiXmlText("How are you?");
	element2->LinkEndChild(text2);

	TiXmlElement * element3 = new TiXmlElement("Language");
	element2->LinkEndChild(element3);

	TiXmlText * text3 = new TiXmlText("English");
	element3->LinkEndChild(text3);

	TiXmlElement * element4 = new TiXmlElement("Exclamation");
	element->LinkEndChild(element4);

	TiXmlText * text4 = new TiXmlText("You have children!");
	element4->LinkEndChild(text4);

	TiXmlElement *element5 = new TiXmlElement("Number of Children");
	element->LinkEndChild(element5);

	TiXmlText *text5 = new TiXmlText("I have 2 :-)");
	element5->LinkEndChild(text5);

	//TiXmlElement *element6 = new TiXmlElement("Test Node");
	cout <<element5->GetText();

	//dump_to_stdout(&doc);
	doc.SaveFile("Demo.xml");
}

void write_simple_doc()
{
	// Make xml: <?xml ..><Hello>World</Hello>
	TiXmlDocument doc;
	TiXmlDeclaration * decl = new TiXmlDeclaration("1.0", "", "");
	TiXmlElement * element = new TiXmlElement("Hello");
	TiXmlText * text = new TiXmlText("World");
	element->LinkEndChild(text);
	doc.LinkEndChild(decl);
	doc.LinkEndChild(element);

	//dump_to_stdout(&doc);
	doc.SaveFile("madeByHand.xml");
	
}*/

void saveData(day dayArr[]) 
{
	
	//TiXmlEncoding UTF8;
	TiXmlDeclaration* declaration = new TiXmlDeclaration("1.0","UTF-8","no");//Create DTD
	TiXmlDocument* doc = new TiXmlDocument;
	doc->LinkEndChild(declaration);


	struct day
	{
		string name;
		string note;
	} dayArray;

	struct day dayArrays[7];

	for (int i = 0; i < 7; i++)
	{

		TiXmlElement* week = new TiXmlElement("week");
		TiXmlElement* day = new TiXmlElement("day");
		TiXmlElement* name = new TiXmlElement("name");
		TiXmlElement* note = new TiXmlElement("note");
		TiXmlElement* tl = new TiXmlElement("tl");
		TiXmlElement* ti = new TiXmlElement("ti");
		TiXmlText* dayName = new TiXmlText("");
		TiXmlText* dayNote = new TiXmlText("");

		//dayArrays[i].name;
		dayArrays[0].name = "Hello";
		dayArrays[1].name = "john";
		dayArrays[2].name = "paul";
		dayArrays[3].name = "Julia";
		dayArrays[4].name = "Johnny Cage";
		dayArrays[5].name = "Facebook";
		dayArrays[6].name = "Alexis";

		dayName = new TiXmlText(dayArrays[i].name.c_str());
		

		dayArrays[0].note =
			"First";
		dayArrays[1].note = "Second";
		dayArrays[2].note = "Third";
		dayArrays[3].note = "Fourth";
		dayArrays[4].note = "Fifth";
		dayArrays[5].note = "Sixth";
		dayArrays[6].note = "Seventh";

		dayNote = new TiXmlText(dayArrays[i].note.c_str());
		name->LinkEndChild(dayName);
		note->LinkEndChild(dayNote);
		day->LinkEndChild(name);
		day->LinkEndChild(note);


		week->LinkEndChild(day);
		doc->LinkEndChild(week);
	}
	while (
		!doc->SaveFile("C:\\Users\\ge040\\Documents\\Visual Studio 2015\\Projects\\Array\\DemoTiny.xml"))
	{
		std::cout << "File not created " << endl;
	}
	//doc->SaveFile("test.xml");
	cout << "SAVED";
}
/*
void saveData2(std::vector<day*> vecDay)
{
	TiXmlDeclaration* declaration = new TiXmlDeclaration("1.0", "UTF-8", "no");//Create DTD
	TiXmlDocument* doc = new TiXmlDocument;
	doc->LinkEndChild(declaration);

	TiXmlElement* week = new TiXmlElement("week");

	for (std::vector<day*>::iterator it = vecDay.begin(); it != vecDay.end(); it++)
	{
		TiXmlElement* day_ = new TiXmlElement("day");
		TiXmlElement* name = new TiXmlElement("name");
		TiXmlElement* note = new TiXmlElement("note");
		TiXmlElement* tl = new TiXmlElement("tl");
		TiXmlElement* ti = new TiXmlElement("ti");
		TiXmlText* dayName = new TiXmlText("");
		TiXmlText* dayNote = new TiXmlText("");
		dayName = new TiXmlText((*it)->name);
		dayNote = new TiXmlText((*it)->note);
		name->LinkEndChild(dayName);
		note->LinkEndChild(dayNote);
		day_->LinkEndChild(name);
		day_->LinkEndChild(note);
		week->LinkEndChild(day_);
	}

	doc->LinkEndChild(week);

	doc->SaveFile("test2.xml");
	cout << "SAVED" << endl;
}

*/
int main(){
	//saveData2("monday");
//	day dayName[7];
	//day Bday[i];
	//saveData(dayName);
	struct test testArray[16];
	//vector<test> customTest2;
	SaveToXML(testArray);
	cout << forCount;
	//write_simple_doc();
	system("pause");
	return 0;
}
