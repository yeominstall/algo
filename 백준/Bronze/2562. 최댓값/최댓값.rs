use std::io;

fn main()
{
    let mut maxval = 0;
    let mut idx = -1;
    for num in (1..10).rev()
    {
        let mut input = String::new();
        io::stdin().read_line(&mut input).expect("");
        let a: u32 = input.trim().parse().expect("");
        if maxval < a
        {
            maxval = a;
            idx = 10 - num;
        }
    }
    println!("{}", maxval);
    println!("{}", idx);
}