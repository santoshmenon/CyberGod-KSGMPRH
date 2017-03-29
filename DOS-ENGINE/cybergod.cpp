// SWAMI KARUPPASWAMI THUNNAI


#include<iostream>
#include"scanner.h"
#include"Malware.h"
#include"duplicates.h"
#include"recovery.h"
#include"shortcutvirus.h"
#include"gutmann.h"
#include"identity.h"
#include"conversions.h"
#include"password_check.h"
#include"autorun.h"
#include"usb.h"
#include<extras.h>
#include"plugin.h"


int wmain(int argc,wchar_t* argv[])
{
	std::cout << "===================================\n";
	std::cout << "| CyberGod KSGMPRH - DOS ENGINE   |\n";
	std::cout << "| A GPL Licensed Security Toolkit |\n";
	std::cout << "| (C) 2017, VISWESWARAN NAGASIVAM |\n";
	std::cout << "===================================\n";
	int option;
	std::cout << "1. Malware scan\n2.Duplicate Files Remover\n3.Recovery\n4.Secure remove\n5. Remove the shortcut virus\n6.Show Identiity\n7. Password strength checker\n8. Autorun Checker\n9. Scan USB\n10. Quick scan\nChoice : ";
	std::cin >> option;
	std::cin.ignore();
	std::wstring global_location;
	std::cout << "\nEnter the location :";
	std::getline(std::wcin, global_location);
	switch (option)
	{
	case 1:
	{
		system("cls");
		Malware<std::wstring> obj;
		obj.set_boost_scan(false);
		obj.scan(global_location.c_str());
		obj.scan_scheduled_files();
		obj.display_suspicious_files();
		break;
	}
	case 2:
	{
		Duplicates<std::wstring> obj1;
		obj1.scan(global_location.c_str());
		obj1.find_the_duplicates();
		obj1.get_duplicates();
		process();
		break;
	}
	case 3:
	{
		Recovery<std::wstring> constructor;
		Recovery<std::wstring> recover(L"G:\\", L"F:\\");
		recover.end();
		break;
	}
	case 4:
	{
		std::string loc = "G:\\CyberGod Recovery Data";
		Gutmann remove;
		remove.secure_pass(L"F:\\dupes\\a.png");
		break;
	}
	case 5:
	{
		ShortCutVirusRemover<std::wstring> rem;
		rem.set_drive_letter("I:\\");
		if (rem.get_scan_status() == true)
		{
			rem.scan(L"I:\\");
			rem.remove_all_shotcuts();
			rem.show_suspected_files();
			rem.fix_infection();
			//rem.remove_autorun("I:\\");
			process();
		}
		break;
	}
	case 6:
	{
		Identity<std::wstring> identify;
		identify.display();
		break;
	}
	case 7:
	{
		std::string password;
		std::cout << "Enter the password to check?" << std::endl;
		std::cin >> password;
		PasswordCheck check = password;
		std::cout <<"\ncapitals : " <<check.get_capital_count() << "\n";
		std::cout << "\nlowers : " << check.get_lower_count() << "\n";
		std::cout << "\nnumbers : " << check.get_number_count() << "\n";
		std::cout << "\nsymbols : " << check.get_symbol_count() << "\n";
		std::cout << "\nwhitespaces : " << check.get_whitespace_count() << "\n";
		std::cout << "\nno of guesses needed to crack this password: " << std::to_string(check.return_guess_count()) << "\n";
		break;
	}
	case 8:
	{
		Autorun<std::wstring> autorun;
		autorun.add_autorun_executables("I:\\");
		if (autorun.check_autorun_file()) 
		{
			autorun.get_hashes();
			autorun.locate();
			autorun.display();
		}
		else process();
		break;
	}
	case 9:
	{
		USBScan<std::wstring> usb;
		usb.initialize("I:\\");
		std::cout << "\nMalicious\n";
		usb.show_malicious_files();
		std::cout << "\nSemi-Malicious\n";
		usb.show_semi_malicious_files();
		std::cout << "\nScanned\n";
		usb.show_files_scanned_in_pc();
		break;
	}
	case 10:
	{
		std::wstring app_data = known_location(FOLDERID_AppsFolder);
		std::wstring program_filesx86 = known_location(FOLDERID_ProgramFilesX86);
		std::wstring windows = known_location(FOLDERID_Windows);
		Malware<std::wstring> obj;
		obj.set_boost_scan(false);
		obj.scan(app_data.c_str());
		obj.scan(program_filesx86.c_str());
		obj.scan(windows.c_str());
		obj.scan_scheduled_files();
		obj.display_suspicious_files();
		break;
	}
	case 11:
	{
		Plugin plugin;
		plugin.get_available_plugins();
		plugin.execute_plugin("plugin.py",argc,argv);
		break;
	}
	default:
		break;
	}
	int stop;
	std::cin >> stop;
}




