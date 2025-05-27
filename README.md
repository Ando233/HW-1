本系统使用 **RM2PT**工具，旨在将需求模型自动转换为系统架构设计和面向对象详细设计。

## 任务1：架构设计自动生成（RapidMS）

通过需求模型，自动生成系统的概念架构设计，主要包括：

**Conceptual Class Diagram：描述系统中的主要业务实体及其关系，帮助开发人员理解系统核心概念及其联系。

**MicroServiceModel**：将系统拆分为多个微服务，定义各个服务的职责边界及交互方式，支持系统的分布式部署与弹性扩展。

截图如下：

![截屏2025-05-27 01.12.23](/Users/ando/Library/Application Support/typora-user-images/截屏2025-05-27 01.12.23.png)

![截屏2025-05-27 01.13.12](/Users/ando/Library/Application Support/typora-user-images/截屏2025-05-27 01.13.12.png)

![截屏2025-05-27 01.14.05](/Users/ando/Library/Application Support/typora-user-images/截屏2025-05-27 01.14.05.png)

Conceptual Class Diagram

![截屏2025-05-27 01.15.22](/Users/ando/Library/Application Support/typora-user-images/截屏2025-05-27 01.15.22.png)

MicroServiceModel

![截屏2025-05-27 01.15.53](/Users/ando/Library/Application Support/typora-user-images/截屏2025-05-27 01.15.53.png)

## 任务2：面向对象详细设计自动生成

在架构设计基础上，进一步自动生成系统的详细设计，主要包括：

**Class Diagram：详细描述系统各个类的属性、方法以及类之间的关系，作为后续代码实现的蓝图。

**Sequence Diagram**：展示不同对象之间的交互流程，体现业务用例在系统中的执行步骤，帮助开发人员理解系统运行机制。

Class Diagram

![截屏2025-05-27 11.06.09](/Users/ando/Library/Application Support/typora-user-images/截屏2025-05-27 11.06.09.png)

![截屏2025-05-27 11.06.30](/Users/ando/Library/Application Support/typora-user-images/截屏2025-05-27 11.06.30.png)

![截屏2025-05-27 11.06.42](/Users/ando/Library/Application Support/typora-user-images/截屏2025-05-27 11.06.42.png)

若干Sequence Diagram如下：

![截屏2025-05-27 11.08.01](/Users/ando/Library/Application Support/typora-user-images/截屏2025-05-27 11.08.51.png)

![截屏2025-05-27 11.09.09](/Users/ando/Library/Application Support/typora-user-images/截屏2025-05-27 11.09.09.png)

## 任务3 大模型生成设计模型与微服务拆分

### 通用Prompt

你是一个专业的软件架构师，精通领域建模、系统设计和需求分析。现在请你根据给定的需求模型（需求用例、需求规范、实体及关系说明），自动生成对应的系统设计模型。设计模型应符合面向对象和微服务架构的最佳实践，并与需求模型保持一致。

**需求：**

基于以下需求模型描述：

{{实验一的需求描述}}

请生成：

1. 架构设计模型：

Conceptual Class Diagram（概念类图）：请列出系统中核心概念及其关系，使用面向对象设计表示。

MicroServiceModel（微服务模型）：请根据业务边界划分微服务，说明每个微服务的职责与接口，画出微服务之间的交互关系。

2. 面向对象详细设计模型：

Class Diagram（类图）：在概念类图的基础上，补充类的属性、方法和接口，体现系统详细设计。

Sequence Diagram（序列图）：针对核心业务场景，生成对应的交互流程图，描述对象间消息传递顺序。

### 大模型输出

#### 概念类图

**概念类图（Conceptual Class Diagram）**

​	•	**User**

​	•	Attributes: userID, name, password, role (Librarian/Student)

​	•	Relations:

​	•	1 User *–* 0..* Loan

​	•	1 User *–* 0..* Search

​	•	1 User *–* 0..* Fine

​	•	**Book**

​	•	Attributes: ISBN, title, author, publicationYear, quantity, status

​	•	Relations:

​	•	1 Book *–* 0..* Loan

​	•	1 Book *–* 0..* Reservation

​	•	**Loan**

​	•	Attributes: loanID, startDate, dueDate, returnDate, status, fineAmount

​	•	Relations:

​	•	1 Loan *–* 1 User

​	•	1 Loan *–* 1 Book

​	•	**Reservation**

​	•	Attributes: reservationID, reservationDate, status

​	•	Relations:

​	•	1 Reservation *–* 1 User

​	•	1 Reservation *–* 1 Book

​	•	**Fine**

​	•	Attributes: fineID, amount, reason, status, createdAt

​	•	Relations:

​	•	1 Fine *–* 1 User

​	•	**LibrarySystem**

​	•	Handles validation, inventory management, notifications, offline mode, and logging.

#### **微服务模型（MicroServiceModel）**

![截屏2025-05-27 11.21.34](/Users/ando/Library/Application Support/typora-user-images/截屏2025-05-27 11.21.34.png)

#### **类图（Class Diagram）**

在概念类图基础上，增加属性与方法：

​	•	**User**

​	•		•	login()

​	•		•	logout()

​	•		•	manageAccount()

​	•	**Book**

​	•		•	addBook()

​	•		•	removeBook()

​	•		•	validateISBN()

​	•		•	updateQuantity()

​	•	**Loan**

​	•		•	createLoan()

​	•		•	closeLoan()

​	•		•	calculateFine()

​	•	**Reservation**

​	•		•	placeReservation()

​	•		•	cancelReservation()

​	•		•	notifyAvailability()

​	•	**Fine**

​	•		•	generateFine()

​	•		•	waiveFine()

​	•	**LibrarySystem**

​	•		•	validateInput()

​	•		•	logAction()

​	•		•	manageInventory()

​	•		•	sendNotification()

​	•		•	handleOfflineMode()

#### **核心场景序列图（以“添加新书”和“借书”为例）**

**📚 场景1：添加新书（Librarian 添加新书）**

```
Librarian -> LibrarySystem : login()
Librarian -> LibrarySystem : selectAddBook()
Librarian -> LibrarySystem : enterBookDetails()
LibrarySystem -> LibrarySystem : validateISBN()
LibrarySystem -> Database : checkDuplicateISBN()
Database --> LibrarySystem : duplicateExists / notExists
alt new book
    LibrarySystem -> Database : createCatalogEntry()
else existing book
    LibrarySystem -> Database : incrementQuantity()
end
LibrarySystem -> Librarian : showConfirmation(newBookID)
LibrarySystem -> Inventory : updateAvailability()
```

**场景2：借书（Student 借阅图书）**

```
Student -> LibrarySystem : login()
Student -> LibrarySystem : selectBorrowBook()
LibrarySystem -> Database : getAvailableBooks()
LibrarySystem -> Student : displayBookList()
Student -> LibrarySystem : selectBook()
LibrarySystem -> Database : checkAvailability()
LibrarySystem -> UserService : checkLoanLimit()
alt allowed
    LibrarySystem -> Database : recordLoan()
    LibrarySystem -> NotificationService : sendConfirmationEmail()
    LibrarySystem -> Inventory : updateBookStatus()
else limit exceeded
    LibrarySystem -> Student : showLimitWarning()
end
```

