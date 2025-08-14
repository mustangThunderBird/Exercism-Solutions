class School:
    def __init__(self):
        self.school_roster = {}
        self.student_added = []

    def add_student(self, name, grade):
        if grade not in self.school_roster.keys():
            self.school_roster[grade] = []
            
        all_students = [v for k,v in self.school_roster.items()]
        for students in all_students:
            if name in students:
                self.student_added.append(False)
                return
                
        self.school_roster[grade].append(name)
        self.school_roster[grade] = sorted(self.school_roster[grade])
        self.student_added.append(True)
            
    def roster(self):
        r = []
        sorted_grades = sorted(list(self.school_roster.keys()))
        for grade in sorted_grades:
            students = self.school_roster[grade]
            for student in students:
                r.append(student)
        return r

    def grade(self, grade_number):
        return self.school_roster.get(grade_number, [])

    def added(self):
        return self.student_added