As a Librarian, I want to add new books, so that library collection can be updated
{
Basic Flow {
		(User) 1. the Librarian shall login to library management system with valid credentials.
		(User) 2. the Librarian shall select Add New Book function from main menu.
		(User) 3. the Librarian shall enters book details including title and author and ISBN and publication year and quantity.
		(System) 4. When ISBN is entered, the LibrarySystem shall validate ISBN format.
		(System) 5. When all required fields are filled, the LibrarySystem shall check for duplicate ISBN in database.
		(System) 6. When book is new because of ISBN not exists, the LibrarySystem shall create new catalog entry.
		(System) 7. When book already exists, the LibrarySystem shall increment existing book quantity.
		(System) 8. the LibrarySystem shall generate and display confirmation message with new book ID.
		(System) 9. When record is savd, the LibrarySystem shall update inventory count and make book immediately available for loan.
	}

	Alternative Flow {
	A. At any time, Administrator requests a priority override :
	1. System enters Administrative priority mode.
	2. Librarian performs high priority operations bulk import override system validations etc.
	3. System logs all override actions with administrator ID.
	4. System reverts to normal operation mode.
	
	B. At any time, System validation fails :
	To maintain data integrity ensure all book records meet cataloging standards.
	1. System identifies all validation errors.
	2. System prevents record submission.
	3. System generates detailed error report highlighting all issues.
	4. System provides corrective suggestions.
	
	C. At any time, Network connection is lost :
	1. System automatically activates offline caching mode.
	2. System stores all data entries locally.
	3. System displays persistent connection status indicator.
	4. System synchronizes cached data with central server.
	5. System resolves any data conflicts using timestamp priority.
	}
}

As a Student, I want to borrow books, so that I can read them
{
Basic Flow {
		(User) 1. the Student shall login to system with student ID and password.
		(User) 2. the Student shall select Borrow Book function.
		(System) 3. the LibrarySystem shall display available books.
		(User) 4. the Student shall select a book to borrow.
		(System) 5. the LibrarySystem shall check book availability status.
		(System) 6. the LibrarySystem shall verify their current loan count does not exceed limit.
		(System) 7. the LibrarySystem shall record their loan transaction with due date.
		(System) 8. the LibrarySystem shall update their book status to Checked Out.
		(System) 9. the LibrarySystem shall send confirmation email to their registered email address.
	}

Alternative Flow {
	A. At any time, Selected book becomes unavailable :
		1. System detects concurrent checkout by another student.
		2. System displays This book was just checked out by another patron alert.
		3. System provides option to reserve next available copy.
		4. System suggests similar available titles.
	
	B. At any time, Student account reaches loan limit :
		1. System blocks new loan requests.
		2. System displays Maximum loan limit reached notification.
		3. System generates personalized return schedule suggestion.
		4. System provides early return incentive options.
	
	C. At any time, System detects account hold :
		1. System verifies hold reason.
		2. System displays detailed hold information.
		3. System provides resolution instructions.
		4. System directs to librarian assistance.
	
	D. At any time, Network connectivity is lost :
		1. System activates offline borrowing mode.
		2. System generates provisional loan receipt.
		3. System queues synchronization.
		4. System notifies student about pending verification.
	}
}

As a Librarian, I want to manage member accounts, so that library users can be properly registered
{
Basic Flow {
    (User) 1. the Librarian shall select Member Management from admin menu.
    (User) 2. the Librarian shall choose Add New Member option.
    (User) 3. the Librarian shall enter member details including name and ID number and contact information.
    (System) 4. When ID number is entered, the LibrarySystem shall validate its uniqueness.
    (System) 5. the LibrarySystem shall generate a unique library card number.
    (System) 6. the LibrarySystem shall save new member record to database.
}

Alternative Flow {
    A. At any time, Duplicate member ID is detected :
        1. System verifies existing member record in database.
        2. System displays Member ID already registered to alert.
        3. System provides options to View existing member details and generate new suggested ID and override with supervisor approval.
    
    B. At any time, Required information is incomplete :
        1. System identifies missing mandatory fields.
        2. System displays Complete all required fields warning.
        3. System dynamically updates completion status as fields are filled.
        4. System enables submit button only.
    
    C. At any time, System detects suspicious registration activity :
        1. System analyzes registration patterns.
        2. System requires secondary authentication for suspicious cases.
        3. System generates security audit log entry.
        4. System notifies administrator.
    
    D. At any time, Database connection fails during registration :
        1. System activates emergency local storage mode.
        2. System issues provisional library card with.
        3. System automatically retries database connection.
        4. System synchronizes all pending registrations.
}
}

As a Student, I want to search for books, so that I can find materials I need
{
Basic Flow {
    (User) 1. the Student shall enter search keywords in search box.
    (System) 2. the LibrarySystem shall return matching books.
    (System) 3. the LibrarySystem shall display results with Cover images and Availability status.
    (User) 4. the Student shall click on a book to view detailed information.
    (System) 5. the LibrarySystem shall display full catalog details including Book summary and Related titles.
}

Alternative Flow {
    A. At any time, Search returns no matching results :
        1. System analyzes search patterns and identifies potential.
        2. System provides No results found for keywords with.
        3. System displays trending titles in related categories.
    
    B. At any time, Search query times out :
        1. System monitors response time.
        2. System switches to cached results with freshness indicator.
        3. System provides Refine your search suggestions.
        4. System logs performance issue for administrator.
    
    C. At any time, Student selects restricted material :
        1. System verifies access permissions based on Student age or grade level and Content restrictions.
        2. System displays Access Restricted notice with Reason for restriction and Request access procedure.
    
    D. At any time, System detects high demand for title :
        1. System identifies titles with Waitlist  over five patrons and Multiple concurrent searches.
        2. System suggests electronic book alternatives and library loan options and Reservation queue position.
        3. System notifies librarian for collection development.
}
}

As a Librarian, I want to track overdue books, so that I can remind users to return them
{
Basic Flow {
    (System) 1. the LibrarySystem shall automatically scan for due books every hour starting at six AM.
    (System) 2. System shall calculate fine and freeze their account fine exceeds and update real time inventory status because of a book becomes overdue.
    (System) 3. nine clock AM daily LibrarySystem shall Generate personalized email or SMS reminders and Update librarian dashboard with.
    (System) 4. the LibrarySystem shall automatically escalate reminders notice after one day overdue and notice after three days and after seven days with librarian intervention required.
}

Alternative Flow {
    A. At any time, Borrower disputes overdue fine :
        1. System provides full audit trail showing check out or return timestamps and reminder history and fine calculation details.
        2. System enables librarian to waive fines with reason codes and adjust payment plans and extend grace periods.
        3. System updates their account in real time.
    
    B. At any time, High value item becomes overdue :
        1. System identifies special collections or reserve items.
        2. System triggers immediate actions.
        3. System generates incident report.
        C. At any time, System detects potential lost item :
        1. System Change status to Assumed Lost and Calculate replacement cost and Block all borrower privileges after ten days overdue.
        2. System provides options to Pay replacement fee and Submit appeal form and Replace identical item.
    
    D. At any time, Borrower returns damaged item :
        1. System guides librarian through damage assessment.
        2. System generates damage report with previous incident condition records and Repair cost estimates and Borrower responsibility statement.
}
}

As a Student, I want to return books, so that others can borrow them
As a Student, I want to check loans, so that I can extend reading time and borrow books
As a Librarian, I want to remove old books, so that catalog stays relevant