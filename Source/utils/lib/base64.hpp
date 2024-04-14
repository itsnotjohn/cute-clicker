#define BASE64 "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/"

namespace base64 {
	inline std::string int2bin(int n, int bits = 8) {
		std::string r = std::string(bits, '0');
		while (n) {
			r.at(--bits) = ((n & 1) + 48);
			n >>= 1;
		}
		return r;
	}

	inline int bin2int(std::string b) {
		int r = 0;
		for (int i = 0; i < b.length(); i++) r += b.at(b.length() - 1 - i) == '1' ? pow(2, i) : 0;
		return r;
	}

	inline std::string Decrypt(std::string t) {
		if (t == "") return "";

		int numero_ceros = 0;
		while (t.at(t.length() - 1) == '=') {
			numero_ceros += 2;
			t = t.substr(0, t.length() - 1);
		}

		std::string b = "", r = "";
		for (auto c : t) b += int2bin(std::string(BASE64).find(c), 6);

		b += std::string('0', numero_ceros);
		for (int i = 0; i < b.length(); i += 8) r += bin2int(b.substr(i, 8));
		return r;
	}
}