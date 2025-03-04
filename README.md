# baitapDeQuy
# Báo cáo Bài tập lớn - Nhóm 14

## 1. Thông tin nhóm
| STT | Họ và tên | MSSV | Vai trò |
|---|---|---|---|
| 1 | Phạm Minh Hải | 24022788 | Nhóm trưởng |
| 2 | Lê Việt Hà | 24022786 | Thành viên |
| 3 | Phạm Đức Thịnh | 24022834 | Thành viên |
| 4 | Phạm Gia Hưng | 24022797| Thành viên |
| 5 | Phạm Thế Hùng | 24022795 | Thành viên |

---

## 2. Thông tin bài tập
- **Tên bài toán**: Giải quyết bài toán Knight Tours: Trên bàn cờ NxN, con mã điểm (x,y). Tìm đường đi qua mọi ô đúng 1 lần.
  

---

## 3. Hướng giải quyết bài toán
### a. Phân tích bài toán
**Input:**
Kích thước bàn cờ N (N ≥ 1).
Vị trí ban đầu của con mã (x, y).

**Output:**
Một dãy các bước đi hợp lệ của con mã sao cho nó đi qua mọi ô đúng một lần.
Nếu có nhiều lời giải, có thể xuất ra một lời giải bất kỳ. Nếu không có lời giải, thông báo không tìm được.

**Ràng buộc:**
Con mã chỉ được di chuyển theo quy tắc của cờ vua (chữ "L" - đi 2 ô theo một hướng và 1 ô theo hướng vuông góc).
Mỗi ô trên bàn cờ chỉ được đi qua đúng một lần.

### b. Thuật toán/Hướng tiếp cận

**1.Xác định kết quả cho hàm Funtions:**
Vì đề nói rõ yêu cầu:"Tìm đường đi" là sẽ in ra ma trận đường đi.
Tuy nhiên ta phải xác định ô đó hợp lệ hay không?
Vì vậy nó phải return true/false.
Suy ra,nó phải là hàm bool.

**2.Base case:**
Điều kiện dừng khi nó đi đủ NxN lượt đi
Suy ra,move.count=n*n

**3.Làm sao để tạo ra 8 hướng đi:**
Ta thấy,một cách dùng if-else(không gọn).
Dùng vòng for.
.Vì ở đây ta không dùng struct nên không return đc local.x và local.y nên ta sẽ đi tìm vị trí x,y tiếp theo và lưu nó vào biến địa phương.
.Trong một lượt mã chỉ đi tối đa 8 cách:
+)Bước 1:đi sang ngang hoặc dọc hai bước:
Tức là,sẽ cộng {2,-2} theo x hoặc {2,-2} theo y
+)Bước 2:đi sang ngang hoặc dọc một bước:
tương tự cộng {1,-1} theo x hoặc {1,-1) theo y
Ở đây dùng for vì nó như là cách đếm các trường hợp.
Ta sẽ tạo một mảng để cộng thêm tham số vào x hoặc y để tạo next.x và next.y

**4.Xác định các bước đi không hợp lệ.**
a.Vượt quá khỏi ô cờ:x>N||y>N
b.Ô trước đó đã đi:
.Lập mảng 2 chiều:lưu kq,lúc đầu cho hết là -1,khi bước đi hợp lệ đổi thành moveCount.

**5.Đệ quy:**
.Xác định tham số của hàm:
+)Toạ độ x và y.
+)Vậy cái gì làm trong tham số làm thay đổi hàm đệ quy?
*Ta còn cần một tham số moveCount để dừng hàm.
Funtion(next.x,next.y,movecount+1)

**6.Quay lùi.**
.Khi thăm hết sẽ phải reset lại tọa độ vị trí của next(x,y) về -1.

---

## 4. Ví dụ minh hoạ
### Ví dụ 1
**Input:**  
3 0 0 
**Output:**  
Khong tim thay duong di phu hop 
**Giải thích:**  
(Mô tả cách giải)

### Ví dụ 2
**Input:**  
3 1 2
**Output:**  
Khong tim thay duong di phu hop
**Giải thích:**  
(Mô tả cách giải)

### Ví dụ 3
**Input:**  
8 0 0 
**Output:**  
| 0 | 59 | 38 | 33 | 30 | 17 | 8 | 63 |

| 37 | 34 | 31 | 60 | 9 | 62 | 29 | 16 |

| 58 | 1 | 36 | 39 | 32 | 27 | 18 | 7 |

| 35 | 48 | 41 | 26 | 61 | 10 | 15 | 28 |

| 42 | 57 | 2 | 49 | 40 | 23 | 6 | 19 |

| 47 | 50 | 45 | 54 | 25 | 20 | 11 | 14 |

| 56 | 43 | 52 | 3 | 22 | 13 | 24 | 5 |

| 51 | 46 | 55 | 44 | 53 | 4 | 21 | 12 |  
**Giải thích:**  
(Mô tả cách giải)

### Ví dụ 2
**Input:**  
6 2 2
**Output:**  
| 30 | 33 | 14 | 5 | 24 | 35 |

| 15 | 22 | 31 | 34 | 13 | 4 |

| 32 | 29 | 0 | 23 | 6 | 25 |

| 19 | 16 | 21 | 10 | 3 | 12 |

| 28 | 9 | 18 | 1 | 26 | 7 |

| 17 | 20 | 27 | 8 | 11 | 2 |

**Giải thích:**  
(Mô tả cách giải)

---

## 5. Link video báo cáo
[Video báo cáo nhóm X](#)

---

## 6. Link source code
[Thư mục src](./src)
