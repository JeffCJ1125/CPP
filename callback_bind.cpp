#include <functional>
#include <iostream>
#include <vector>

using namespace std;

void the_static_function(string str) {
  cout << "the static function " << str << endl;
}

class baseclass {
 private:
  string name;

 public:
  baseclass(string str) : name(str) {}

  virtual void print_str(string input_str) {
    name = input_str;
    cout << "base print " << name << endl;
  }

  // virtual void pure_virtual(string input_str) = 0;
  void get_name() { cout << name << endl; }
};

class subclass : baseclass {
 private:
  string name;

 public:
  subclass(string str, string base_str = "sub_base")
      : baseclass(base_str), name(str)  {}

  void print_str(string input_str) {
    name = input_str;
    cout << "subclass print " << name << endl;
  }

  // void pure_virtual(string inputstr) override {
  //     cout << "override" << endl;
  // }
  void get_name() { cout << name << endl; }
};

class manager {
  using callback = std::function<void(string)>;

  vector<callback> cbs;

 public:
  int register_cb(const callback &cb) {
    if (cb) {
      cbs.push_back(cb);
      return 0;
    } else {
      cout << "register_error" << endl;
      return -1;
    }
  }
  void trigger_cbs(string inputstr) {
    for (auto &cb : cbs) {
      cb(inputstr);
    }
  }
};

int main(int argc, char *argv[]) {
  manager mg;
  baseclass base("base");

  subclass sub("sub");

  cout << "the_static_function register :"
       << mg.register_cb(the_static_function) << endl;
  cout << "use lambda function register base class member function:"
       << mg.register_cb([&](string input_str) { base.print_str(input_str); })
       << endl;
  cout << "use lambda function register sub class member function:"
       << mg.register_cb([&](string input_str) { sub.print_str(input_str); })
       << endl;
  cout << "lambda function register :" << mg.register_cb([&](string input_str) {
    cout << "lambda function : " << input_str << endl;
  }) << endl;

  mg.trigger_cbs("things happen");

  return 0;
}