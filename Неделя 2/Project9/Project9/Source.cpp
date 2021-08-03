#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>
#include <map>

using namespace std;

int main() {
	int Q, i = 0, h = 0, stop_counts;
	map<string, int> stop_counts_of_bus;
	map<string, vector<string>> route_of_bus;
	map<string, vector<string>> bus_for_stop;
	string command, stops, bus, stop;
	vector<string> vector_stops, vector_buses;
	cin >> Q;

	while(i < Q) {
		cin >> command; 
		if (command == "NEW_BUS") {
			cin >> bus >> stop_counts;
			stop_counts_of_bus[bus] = stop_counts;
			while (h < stop_counts) {
				cin >> stops;
				route_of_bus[bus].push_back(stops);
				bus_for_stop[stops].push_back(bus);
				++h;
			}
		}

		else if (command == "BUSES_FOR_STOP") {
			cin >> stop;
			if (bus_for_stop.count(stop) == 0) {
				cout << "No stop" << endl;
			}
			else {
				vector_buses = bus_for_stop[stop];
				for (int f = 0; f < vector_buses.size(); ++f) {
					cout << vector_buses[f] << " ";
				}
				cout << endl;
			}
		}	

		else if (command == "STOPS_FOR_BUS") {
			cin >> bus;
			if (route_of_bus.count(bus) == 0) {
				cout << "No bus" << endl;
			}
			else {
				vector_stops = route_of_bus[bus];
				for (int u = 0; u < vector_stops.size(); ++u) {
					if ((bus_for_stop[vector_stops[u]]).size() == 1) {
						cout << "Stop " << vector_stops[u] << ":" << " " << "no interchange" << endl;
					}
					else if ((bus_for_stop[vector_stops[u]]).size() > 1) {
						cout << "Stop " << vector_stops[u] << ":" << " "; 
						vector_buses = bus_for_stop[vector_stops[u]];
						for (int g = 0; g < vector_buses.size(); ++g) {
							if (vector_buses[g] != bus) {
								cout << vector_buses[g] << " ";
							}
						}
						cout << endl;
					}
				}
			
			}
		}

		else if (command == "ALL_BUSES") {
			if (route_of_bus.size() == 0) {
				cout << "No buses" << endl;
			}
			else {
				for (auto& pair : route_of_bus) {
					cout << "Bus " << pair.first << ":" << " ";
					for (int d = 0; d < (pair.second).size(); ++d) {
						cout << pair.second[d] << " ";
					}
					cout << endl;
				}
			}
		}

		++i;
	}

	system("pause");
	return 0;
}


/*				
				string name; // исходная строка
				name = route_of_bus[bus];
				string delim = " ";   // строка или символ разделитель
				size_t pos = 0;
				size_t base_str_size = name.size();
				size_t delim_size = delim.size();
				string temp;
				vector<string> temp_list;
				while (pos < base_str_size) {
					temp = temp.assign(name, pos, name.find(delim, pos) - pos);
					if (temp.size() > 0) // проверка на пустую строку при необходимости 
					pos += temp.size() + delim_size;
					temp_list.push_back(temp);
				}
				for (int g = 0; g < temp_list.size(); ++g) {
					if (bus_for_stop.count(temp_list[g]) == 1) { 
						cout << "Stop " << temp_list[g] << ":" << "no interchange" << endl;
					}
					else if (bus_for_stop.count(temp_list[g]) == 1) {
						cout << "Stop " << temp_list[g] << ":" << bus_for_stop[temp_list[g]] << endl;
					} 
				} 
*/