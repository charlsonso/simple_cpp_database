#include <soci/soci.h>
#include <soci/mysql/soci-mysql.h>
#include <exception>
#include <iostream>
#include <string>

using namespace soci;
using std::cin;
using std::cout;
using std::endl;
using std::string;

template<typename T>
void get_data(const string prompt, T& value){
  cout << prompt;
  cin >> value;
}

void insert_user(session& sql,
    const string& first_name,
    const string& last_name,
    const string& email){
  sql << "INSERT INTO users(first_name, last_name email) VALUES(:fn, :ln, :e)",
          user(first_name, "fn"), user(last_name, "ln"), use(email, "e");

  cout << ">Succesfully inserted user." << endl << endl;
}

void display_users(session& sql){
  rowset<row> rs = (sql.prepare << "SELECT * FROM users");

  for (rowset<row>::const_iterator it = rs.begin(); it != rs.end(); ++it){
    const row& r = *it;

    std:: cout << "ID: " << r.get<int>(0) << endl
      << "First Name: " << r.get<string>(1) << endl
      << "Last Name: " << r.get<string>(2) << endl
      << "Email: " << r.get<string>(3) << endl
      << "Active: " << r.get<int>(4) << endl << endl;
  }
}

int main(){
  try {
    session sql(mysql, "db=soci_db user=soci_devl password=Secure123");

    string first_name, last_name, email;

    get_data("> Enter first name: ", first_name);
    get_data("> Enter last name: ", last_name);
    get_data("> Enter email address: ", email);

    insert_user(sql, first_name, last_name, email);

    display_users(sql);
  }
  catch (const std:: exception& e){
    std::cerr << "Error: " << e.what() << endl;
  }

  return 0;

}
