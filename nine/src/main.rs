extern crate image;
use image::ImageDecoder;

use std::fs::File;

fn main() {
    let (buf, width, height) = {
        let mut decoder =
            image::png::PNGDecoder::new(File::open("scrambled-photo-test-bb113a9ce101.png").unwrap());
        let (width, height) = decoder.dimensions().unwrap();
        let frames = decoder.into_frames().unwrap().next().unwrap();
        (frames.into_buffer(), width, height)
    };
    println!("{}, {}", width, height);
    let mut columns: Vec<Vec<image::Rgba<u8>>> = Vec::new();
    for x in 0..width {
        let mut column = Vec::new();
        for y in 0..height {
            column.push(buf[(x, y)]);
        }
        columns.push(column);
    }
    fn int(p: image::Rgba<u8>) -> i32 {
        let r = p[0] as i32;
        let g = p[1] as i32;
        let b = p[2] as i32;
        (r + g + b) / 3
    }
    columns.sort_by(|c1, c2| {
        int(c1[0]).cmp(&int(c2[0]))
    });
    columns.sort_by(|c1, c2| {
        if int(c1[0]) > 100 || int(c2[0]) > 100 { return ::std::cmp::Ordering::Equal }
        fn aux(height: usize, column: &Vec<image::Rgba<u8>>) -> usize {
            let mut i = 0;
            while i < height  && (column[i][1] as i32) < 100 {
                i += 1;
            }
            i
        }
        let a = aux(height as usize, c1);
        let b = aux(height as usize, c2);
        a.cmp(&b)
    });
    /*
    for c in columns {
        println!("{:?}", c[0]);
    }
    */
    let mut newbuf = image::ImageBuffer::new(width, height);

    for x in 0..width {
        for y in 0..height {
            newbuf[(x, y)] = columns[x as usize][y as usize];
        }
    }
    let fout = &mut File::create("out.png").unwrap();
    image::ImageRgba8(newbuf).save(fout, image::PNG).unwrap();
}
