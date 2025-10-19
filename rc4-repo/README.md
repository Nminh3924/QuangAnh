Chuỗi ví dụ "Hanoi University of Science and Technology" được mã hóa với khóa "RC4Key123" để minh họa hoạt động của thuật toán.
Cấu trúc Repository
Repository được tổ chức như sau:
rc4-repo/
├── lib/
│   ├── rc4.h
│   └── rc4.c
├── encrypt_project/
│   ├── main.c
├── decrypt_project/
│   ├── main.c
└── README.md

- encrypt_project: Mã hóa văn bản gốc thành văn bản mã (dạng hex).
- decrypt_project: Giải mã văn bản mã (hex) thành văn bản gốc.


* Cách chạy chương trình
1. Mã hóa văn bản

Thư mục: encrypt_project
Lệnh chạy:./encrypt

Mô tả:
Khóa: RC4Key123
Văn bản gốc: Hanoi University of Science and Technology
Xuất ra văn bản mã dạng hex.

Đầu ra: 14a44411bd2276d0e160a73c138e38943a712c4364dcce966179e5380b4df2f18f10939ad4d30298b229

2. Giải mã văn bản

Thư mục: decrypt_project
Lệnh chạy:./decrypt

Mô tả:
Khóa: RC4Key123
Văn bản mã (hex): 14a44411bd2276d0e160a73c138e38943a712c4364dcce966179e5380b4df2f18f10939ad4d30298b229
Xuất ra văn bản gốc.

Đầu ra: Hanoi University of Science and Technology

* Bộ test vector
Dưới đây là các test vector để kiểm tra tính đúng đắn của triển khai RC4. Các test case sử dụng các khóa và văn bản khác nhau để xác minh mã hóa và giải mã.

- Test Case 1

Khóa: Key
Văn bản gốc: Plaintext
Văn bản mã (hex): bbf316e8d940af0ad3
Cách kiểm tra:
Trong encrypt_project/main.c:
Sửa const char *key = "Key";
Sửa const char *plaintext = "Plaintext";

Biên dịch và chạy: cd encrypt_project
                   gcc main.c ../lib/rc4.c -o encrypt
                   ./encrypt

Kiểm tra đầu ra: bbf316e8d940af0ad3.
Trong decrypt_project/main.c:
Sửa const char *key = "Key";
Sửa const char *ciphertext_hex = "bbf316e8d940af0ad3";

Biên dịch và chạy: cd ../decrypt_project
                   gcc main.c ../lib/rc4.c -o decrypt
                   ./decrypt

Kiểm tra đầu ra: Plaintext.

- Test Case 2

Khóa: Wiki
Văn bản gốc: pedia
Văn bản mã (hex): 1021bf0420
Cách kiểm tra:
Trong encrypt_project/main.c:
Sửa const char *key = "Wiki";
Sửa const char *plaintext = "pedia";

Biên dịch và chạy: cd encrypt_project
                   gcc main.c ../lib/rc4.c -o encrypt
                   ./encrypt

Kiểm tra đầu ra: 1021bf0420.
Trong decrypt_project/main.c:
Sửa const char *key = "Wiki";
Sửa const char *ciphertext_hex = "1021bf0420";

Biên dịch và chạy: cd ../decrypt_project
                   gcc main.c ../lib/rc4.c -o decrypt
                   ./decrypt

Kiểm tra đầu ra: pedia.

- Test Case 3

Khóa: Secret
Văn bản gốc: Attack at dawn
Văn bản mã (hex): 45a01f645fc35b383552544b9bf5
Cách kiểm tra:
Trong encrypt_project/main.c:
Sửa const char *key = "Secret";
Sửa const char *plaintext = "Attack at dawn";

Biên dịch và chạy: cd encrypt_project
                   gcc main.c ../lib/rc4.c -o encrypt
                   ./encrypt

Kiểm tra đầu ra: 45a01f645fc35b383552544b9bf5.
Trong decrypt_project/main.c:
Sửa const char *key = "Secret";
Sửa const char *ciphertext_hex = "45a01f645fc35b383552544b9bf5";

Biên dịch và chạy: cd ../decrypt_project
                   gcc main.c ../lib/rc4.c -o decrypt
                   ./decrypt

Kiểm tra đầu ra: Attack at dawn.
