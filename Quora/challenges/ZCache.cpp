#include <iostream>
#include <unordered_map>
#include <list>
#include <string>

using namespace std;

class cache {
public:
	cache(int capacity):m_capacity(capacity) {
	}
	void set(string key, string value) {
		if(m_map.size() == m_capacity) {
			m_map.erase(m_map.find(*m_list.begin()));
			m_list.erase(m_list.begin());
		}
		if(m_map.count(key)) {
			list<string>::iterator node = m_msi[key];
			m_list.erase(node);
		}
		m_list.push_back(key);
		m_map[key] = value;
		m_msi[key] = --m_list.end();
	}

	string get(string key) {
		if(!m_map.count(key)) {
			return "error";
		}
		list<string>::iterator node = m_msi[key];
		m_list.erase(node);
		m_list.push_back(key);
		m_msi[key] = --m_list.end();
		return m_map[key];
	}

private:
	unordered_map<string, string> m_map;
	unordered_map<string, list<string>::iterator> m_msi;
	list<string> m_list;
	size_t m_capacity;
};

int main() {

  cache ca(3);
  ca.set("a","1");
  ca.set("b","2");
  ca.set("c","3");
  ca.get("b");
  ca.set("d","4");
  ca.set("e","5");
  ca.get("b");
  ca.set("e","5");
  ca.get("b");
  ca.set("f","6");

  cout << ca.get("a") << endl;
  cout << ca.get("b") << endl;
  cout << ca.get("c") << endl;
  cout << ca.get("d") << endl;
  cout << ca.get("e") << endl;
  cout << ca.get("f") << endl;

  return 0;
}

