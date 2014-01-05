#!/bin/perl

use strict;

my %total = ();
my %count = (); 

while(<>){
   chomp;
   my ($runNumber, $sequence, $sendTime, $ss) = split(/,/);
   $total{$runNumber} += $ss;
   $count{$runNumber}++;
}

foreach my $rn (sort {$a <=> $b} keys %total){
   if($count{$rn} == 0){
      print "RUN $rn has zero count\n";
   } else {
      my $avg = $total{$rn} / $count{$rn};
      print "$rn,$avg\n";
   }
}
