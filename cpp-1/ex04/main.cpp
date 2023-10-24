/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhoyer <mhoyer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 14:05:07 by mhoyer            #+#    #+#             */
/*   Updated: 2023/10/08 22:39:56 by mhoyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstddef>
#include <iostream>
#include <string>
#include <fstream>

int main(int ac, char **av) {
	if (ac != 4)
		return (1);
	std::string outfileName = av[1];
	std::string s1 = av[2];
	std::string s2 = av[3];
	std::string lineRead;
	outfileName.append(".replace");

	std::ifstream infile(av[1]);
	if (!infile.is_open()) {
		std::cerr << "Bad file" << std::endl;
		return (1);
	}
	
	std::ofstream outfile(outfileName.c_str());
	if (!outfile.is_open()) {
		std::cerr << "Bad file" << std::endl;
		return (1);
	}

	while (std::getline(infile, lineRead)) {
		size_t isFind = lineRead.find(s1);
		if (isFind < lineRead.length()) {
			std::string::iterator it = lineRead.begin();
			for (size_t i=0; i != isFind; i++) {
				outfile << *it;
				it++;
			}
			outfile << s2;
			it += s1.length();
			while (it != lineRead.end()) {
				outfile << *it;
				it++;
			}
			outfile << std::endl;
		}
		else
		 	outfile << lineRead << std::endl;
	}
	infile.close();
	outfile.close();
	return (0);
}