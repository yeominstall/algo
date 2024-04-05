use std::io;

fn main()
{
    // n
    let mut n = String::new();
    io::stdin().read_line(&mut n).expect("");
    let _a : u32 = n.trim().parse().expect("");

    let mut mx : i32 = -1000001;
    let mut mn : i32 = 1000001;

    // vals
    let mut nums = String::new();
    io::stdin().read_line(&mut nums).expect("");
    let split_string : Vec<&str> = nums.split(' ').collect();
    for _num in split_string
    {
        let num : i32 = _num.trim().parse().expect("");
        if num < mn
        {
            mn = num;
        }
        if num > mx
        {
            mx = num;
        }
    }
    println!("{} {}", mn, mx);
}