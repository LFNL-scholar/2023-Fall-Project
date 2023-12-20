import java.util.ArrayList;
import java.util.Scanner;

class Teacher {
    String teacherNumber;
    String name;
    String gender;
    String unitName;
    String address;
    String phoneNumber;
    double basicSalary;
    double allowance;
    double livingAllowance;
    double telephoneFee;
    double utilityFee;
    double rent;
    double incomeTax;
    double healthFee;
    double providentFund;
    double totalDeductions;
    double grossSalary;

    void calculateSalary() {
        double totalAllowance = basicSalary + allowance + livingAllowance;
        totalDeductions = telephoneFee + utilityFee + rent + incomeTax + healthFee + providentFund;
        grossSalary = totalAllowance - totalDeductions;
    }

    // 添加构造函数
    public Teacher(String teacherNumber, String name, String gender, String unitName, String address, String phoneNumber,
                   double basicSalary, double allowance, double livingAllowance, double telephoneFee, double utilityFee,
                   double rent, double incomeTax, double healthFee, double providentFund) {
        this.teacherNumber = teacherNumber;
        this.name = name;
        this.gender = gender;
        this.unitName = unitName;
        this.address = address;
        this.phoneNumber = phoneNumber;
        this.basicSalary = basicSalary;
        this.allowance = allowance;
        this.livingAllowance = livingAllowance;
        this.telephoneFee = telephoneFee;
        this.utilityFee = utilityFee;
        this.rent = rent;
        this.incomeTax = incomeTax;
        this.healthFee = healthFee;
        this.providentFund = providentFund;
    }

    // 添加toString方法，方便输出
    @Override
    public String toString() {
        return "教师号: " + teacherNumber + "\n姓名: " + name + "\n性别: " + gender + "\n单位名称: " + unitName +
                "\n家庭住址: " + address + "\n联系电话: " + phoneNumber + "\n基本工资: " + basicSalary +
                "\n津贴: " + allowance + "\n生活补贴: " + livingAllowance + "\n应发工资: " + (basicSalary + allowance + livingAllowance) +
                "\n电话费: " + telephoneFee + "\n水电费: " + utilityFee + "\n房租: " + rent +
                "\n所得税: " + incomeTax + "\n卫生费: " + healthFee + "\n公积金: " + providentFund +
                "\n合计扣款: " + totalDeductions +
                "\n实发工资: " + grossSalary +
                "\n============================";
    }
}

public class TeacherSalaryManagementSystem {
    private static ArrayList<Teacher> teachers = new ArrayList<>();
    private static Scanner scanner = new Scanner(System.in);

    public static void main(String[] args) {
        while (true) {
            System.out.println("教师工资管理系统");
            System.out.println("1. 输入教师信息");
            System.out.println("2. 插入（修改）教师信息");
            System.out.println("3. 删除教师信息");
            System.out.println("4. 浏览教师信息");
            System.out.println("5. 退出系统");
            System.out.print("请选择操作（1-5）: ");
            int choice = scanner.nextInt();

            switch (choice) {
                case 1:
                    inputTeacherInfo();
                    break;
                case 2:
                    updateTeacherInfo();
                    break;
                case 3:
                    deleteTeacherInfo();
                    break;
                case 4:
                    displayTeacherInfo();
                    break;
                case 5:
                    System.out.println("感谢使用教师工资管理系统，再见！");
                    System.exit(0);
                default:
                    System.out.println("无效的选项，请重新输入");
            }
        }
    }

    private static void inputTeacherInfo() {
        System.out.println("请输入教师信息：");
        System.out.print("教师号: ");
        String teacherNumber = scanner.next();
        System.out.print("姓名: ");
        String name = scanner.next();
        System.out.print("性别: ");
        String gender = scanner.next();
        System.out.print("单位名称: ");
        String unitName = scanner.next();
        System.out.print("家庭住址: ");
        String address = scanner.next();
        System.out.print("联系电话: ");
        String phoneNumber = scanner.next();
        System.out.print("基本工资: ");
        double basicSalary = scanner.nextDouble();
        System.out.print("津贴: ");
        double allowance = scanner.nextDouble();
        System.out.print("生活补贴: ");
        double livingAllowance = scanner.nextDouble();
        System.out.print("电话费: ");
        double telephoneFee = scanner.nextDouble();
        System.out.print("水电费: ");
        double utilityFee = scanner.nextDouble();
        System.out.print("房租: ");
        double rent = scanner.nextDouble();
        System.out.print("所得税: ");
        double incomeTax = scanner.nextDouble();
        System.out.print("卫生费: ");
        double healthFee = scanner.nextDouble();
        System.out.print("公积金: ");
        double providentFund = scanner.nextDouble();

        teachers.add(new Teacher(teacherNumber, name, gender, unitName, address, phoneNumber,
                basicSalary, allowance, livingAllowance, telephoneFee, utilityFee, rent, incomeTax, healthFee, providentFund));

        System.out.println("教师信息录入成功！");
    }

    private static void updateTeacherInfo() {
        System.out.print("请输入要修改的教师号: ");
        String teacherNumber = scanner.next();
        for (Teacher teacher : teachers) {
            if (teacher.teacherNumber.equals(teacherNumber)) {
                System.out.println("请输入新的教师信息：");
                System.out.print("基本工资: ");
                double basicSalary = scanner.nextDouble();
                System.out.print("津贴: ");
                double allowance = scanner.nextDouble();
                System.out.print("生活补贴: ");
                double livingAllowance = scanner.nextDouble();
                System.out.print("电话费: ");
                double telephoneFee = scanner.nextDouble();
                System.out.print("水电费: ");
                double utilityFee = scanner.nextDouble();
                System.out.print("房租: ");
                double rent = scanner.nextDouble();
                System.out.print("所得税: ");
                double incomeTax = scanner.nextDouble();
                System.out.print("卫生费: ");
                double healthFee = scanner.nextDouble();
                System.out.print("公积金: ");
                double providentFund = scanner.nextDouble();

                teacher.basicSalary = basicSalary;
                teacher.allowance = allowance;
                teacher.livingAllowance = livingAllowance;
                teacher.telephoneFee = telephoneFee;
                teacher.utilityFee = utilityFee;
                teacher.rent = rent;
                teacher.incomeTax = incomeTax;
                teacher.healthFee = healthFee;
                teacher.providentFund = providentFund;

                teacher.calculateSalary();

                System.out.println("教师信息修改成功！");
                return;
            }
        }
        System.out.println("未找到对应教师号的信息！");
    }

    private static void deleteTeacherInfo() {
        System.out.print("请输入要删除的教师号: ");
        String teacherNumber = scanner.next();
        teachers.removeIf(teacher -> teacher.teacherNumber.equals(teacherNumber));
        System.out.println("教师信息删除成功！");
    }

    private static void displayTeacherInfo() {
        System.out.println("教师信息列表：");
        for (Teacher teacher : teachers) {
            System.out.println(teacher.toString());
        }
    }
}