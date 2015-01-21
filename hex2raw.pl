#!/usr/bin/perl
use strict;
use warnings;
my $fil = undef;
open($fil, "<", "raw.txt") || die "$0: cant open raw.txt for reading:
$!";
while (<$fil>){
$_ =~ tr/ //ds;
print pack "H*", $_;
}
close($fil);
