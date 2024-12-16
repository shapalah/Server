#include "Logger.h"
#include "Connector.h"
#include "Calculator.h"
#include "Communicate.h"
#include "Interface.h"
#include <UnitTest++/UnitTest++.h>
#include <limits>
#include <chrono>
#include <thread>
#include <boost/numeric/conversion/cast.hpp>
#define max_pos 65535
#define min_pos 0
#define _UNITTEST_ 1


SUITE(Connector_test) {
    TEST(newl_in_path) {
        Connector Con;
        std::string path = "test_files/auth\n";
        CHECK_THROW(Con.connect(path), crit_err);
    }
    TEST(incorrect_path) {
        Connector Con;
        std::string path = "1111";
        CHECK_THROW(Con.connect(path), crit_err);
    }
    TEST(void_path) {
        Connector Con;
        std::string path = "";
        CHECK_THROW(Con.connect(path), crit_err);
    }
    TEST(wrong_path) {
        Connector Con;
        std::string path = "/sudo/auth.txt";
        CHECK_THROW(Con.connect(path), crit_err);
    }
    TEST(right_path) {
        Connector Con;
        std::string path = "test_files/auth.txt";
        CHECK_EQUAL(0, Con.connect(path));
    }
    TEST(check_reading) {
        Connector Con;
        std::string check_pass = "P@ssW0rd";
        std::string check_login = "user";
        std::string path = "test_files/auth.txt";
        Con.connect(path);
        auto data = Con.get_data();
        CHECK(data.find(check_login) != data.end() && data[check_login] == check_pass);
    }
}

SUITE(Calculator_test) {
    TEST(positiv_overflow) {
        std::vector<double> v = {1.0, 2}; 
        Calculator c(v);
        CHECK_EQUAL(3, c.send_res());
    }
    TEST(negative_number_1) {
        std::vector<double> v = {-10.2, -5.8};
        Calculator c(v);
        CHECK_EQUAL(-16, c.send_res());
    }
    TEST(negative_number_2) {
        std::vector<double> v = {-10, -10};
        Calculator c(v);
        CHECK_EQUAL(-20, c.send_res());
    }
	TEST(single_value) {
        std::vector<double> v = {5}; 
        Calculator c(v);
        CHECK_EQUAL(5, c.send_res());
    }
	TEST(million_ones) {
        std::vector<double> v(1000000, 1);
        Calculator c(v);
        CHECK_EQUAL(1000000, c.send_res());
    }
    TEST(mixed_sign_numbers) {
    	std::vector<double> v = {5.5, -3.5};
    	Calculator c(v);
    	CHECK_EQUAL(2, c.send_res());
	}
	TEST(large_numbers) {
    	std::vector<double> v = {1e6, 1e7, 1e8};
    	Calculator c(v);
    	CHECK_EQUAL(1.11e8, c.send_res());
	}
	TEST(negative_large_numbers) {
    	std::vector<double> v = {-1e6, -2e7, -3e8};
    	Calculator c(v);
    	CHECK_EQUAL(-3.21e8, c.send_res());
	}

	TEST(empty_vector) {
    	std::vector<double> v = {};
    	Calculator c(v);
    	CHECK_EQUAL(0, c.send_res()); 
	}
}

SUITE(Logger_test) {
    TEST(wrong_path) {
        Logger l;
        std::string path = "shapalah/to/log.txt";
        CHECK_THROW(l.set_path(path), crit_err);
    }
    TEST(void_path) {
        Logger l;
        std::string path = "";
        CHECK_THROW(l.set_path(path), std::invalid_argument);
    }
    TEST(correct_path) {
        Logger l;
        std::string path = "test_files/log.txt";
        CHECK_EQUAL(0, l.set_path(path));
    }
    TEST(newl_in_path_log) {
        Logger l;
        std::string path = "test_files/baze\n";
        CHECK_THROW(l.set_path(path), std::invalid_argument);
    }
    TEST(path_with_spaces) {
        Logger l;
        std::string path = "test_files/ lo g.txt";
        CHECK_EQUAL(0, l.set_path(path));
    }
}


SUITE(Client_Communicate) {
    TEST(salt_generator) {
        Communicate com;
        std::string salt_one = com.generate_salt();
        std::this_thread::sleep_for(std::chrono::seconds(1));
        std::string salt_two = com.generate_salt();
        CHECK(salt_one != salt_two);
    }
    TEST(salt_len) {
        Communicate com;
        std::string salt = com.generate_salt();
        CHECK_EQUAL(16, salt.length());
    }
    TEST(sha1_gen) {
        std::string hash_check = "94C831E8CDEA06F25DF92462575681777131DED0";
        Communicate com;
        std::string SALT = "2A2B91EEBB29DC1C";
        std::string hash = com.sha1(SALT);
        CHECK_EQUAL(hash_check, hash);
    }
	TEST(hash_salt_password) {
        Communicate com;
        std::string salt = "2A2B91EEBB29DC1C";
        std::string password = "P@ssW0rd";
        std::string expected_hash = "381C9EE8495726614C1E078E7E342AE0B7D9E9AA";
        std::string combined = salt + password;
        std::string hash = com.sha1(combined);
        CHECK_EQUAL(expected_hash, hash);
    }
    TEST(empty_gen){
		std::string hash_check = "DA39A3EE5E6B4B0D3255BFEF95601890AFD80709";
		Communicate a;
		std::string SALT = "";
		std::string hash = a.sha1(SALT);
		CHECK_EQUAL(hash,hash_check);
	}
}

int main(int argc, char **argv) {
    return UnitTest::RunAllTests();
}
