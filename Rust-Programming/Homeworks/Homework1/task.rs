pub struct NucleotideCounter {
    pub a: usize,
    pub c: usize,
    pub g: usize,
    pub t: usize,
}
+

pub fn counts(dna: &[char]) -> NucleotideCounter {

    let mut counter = NucleotideCounter{
        a:0,
        c:0,
        g:0,
        t:0,
    };
    
    for &n in dna.iter(){
        if n=='A' {
           counter.a += 1;
        }
        else if n=='C'{
           counter.c += 1;
        }
        else if n=='G'{
           counter.g  += 1;
        }
        else if n=='T'{
           counter.t += 1;
        }
        else{
            panic!("Грешка, използвате несъществуваща нуклеотидна база!");
        }
    }
   
    return counter;
}

pub fn dna_complement(dna: &[char]) -> Vec<char> {
    let mut new_dna: Vec<char> = Vec::new();
    for &n in dna.iter(){
        if n == 'A'{
            new_dna.push('T');
        }
        else if n == 'T'{
             new_dna.push('A');
        }
        else if n == 'C'{
             new_dna.push('G');
        }
        else if n == 'G'{
             new_dna.push('C');
        }
        else{
            panic!("Грешка, използвате несъществуваща нуклеотидна база!");
        }
    }
    return new_dna;
}

pub fn reverse_rna_complement(dna: &[char]) -> Vec<char> {
    let mut new_rna: Vec<char> = Vec::new();
    for &n in dna.iter(){
        if n == 'A'{
            new_rna.push('U');
        }
        else if n == 'T'{
             new_rna.push('A');
        }
        else if n == 'C'{
             new_rna.push('G');
        }
        else if n == 'G'{
             new_rna.push('C');
        }
        else{
            panic!("Грешка, използвате несъществуваща нуклеотидна база!");
        }
    }
    new_rna.reverse();
    return new_rna;
}
