# Επίπεδο Εφαρμογής και Μεταφοράς

## Επίπεδο Μεταφοράς

- Στο επίπεδο μεταφοράς δύο είναι τα πρωτόκολλα που χρησιμοποιούνται κυρίως:
  - **_TCP_** (_Transmission Control Protocol_)
  - **_UDP_** (_User Datagram Protocol_)

## TCP

- _Συνδεσμικό πρωτόκολλο (Connection Oriented):_ Πριν την αποστολή των δεδομένων, εγκαθιδρύεται σύνδεση και διατειρέιται καθόλη την διάρκεια της επικοινωνίας. Η σύνδεση κλέινει μόλις η επικοινωνία ολοκληρωθεί.
- _Flow Control:_ Διαθέτει μηχανισμό ελέγχου της ταχύτητας που μεταδίδονται τα πακέτα.
- _Αξιοπιστία:_ Εγγύηση ότι τα πακέτα έχουν φτάσει στον προορισμό, εξασφαλίζοντας παράλληλα και την ακεραιότητα των δεδομένων.

### Εγκαθίδρυση TCP σύνδεσης (Three Way Handshake)

- O Clien στέλνει εκκινεί την σύνδεση στέλνοντας ένα πακέτo με **_SYN bit_** (synchronization bit) ίσο με 1
- Ο Server το λαμβάνει και στέλνει ένα πακέτο με **_SYN_** και **_ΑCK bit_** (acknowledgement bit) ίσα με 1.
- O Clien το λαμβάνει και στέλνει ένα πακέτο με **_ACK_** bit ίσο με 1.

<div style="display:flex;justify-content:center;width:100%;">
   <img src="https://miro.medium.com/v2/resize:fit:720/format:webp/1*IE_SkdCYUrY3HyQ5U59WZg.png" style="width:420px;">
</div>

### Κλείσιμο TCP σύνδεσης

- O client στέλνει ένα πακέτο με **_FIN_** bit (finish bit) ίσο με 1
- O sever το λαμβάνει και στέλνει Αcknowledgement πακέτο με **_ACK_** bit ίσο με 1.
- Ο server στην συνέχεια αποστέλει και αυτός ένα πακέτο με **_FIN_** bit ίσο με 1 (και **_ΑCK_** bit ίσο με 1).
- Ο client λαμβάνει το FIN πακέτο και αποστέλλει **_Acknowledgement_** πακέτο στον server

<div style="display:flex;justify-content:center;width:100%;">
   <img src="https://wiki.wireshark.org/uploads/__moin_import__/attachments/TCP-4-times-close/TCP-close-diagram.png" style="width:400px;">
</div>

### SEQ & ACK numbers

> **_SEQ Number_** _(Sequence Number):_
>
> > Σε ένα πακέτο ο αριθμός **_Sequence_** δηλώνει την σειρά με την οποία στάλθηκαν τα πακέτα. Χρησιμοποιείται από το άλλο άκρο της επικοινωνίας για συναρμολόγηση των πακέτων στην σωστή σειρά ή και για άιτηση επαναμετάδοσης κάποιου πακέτου
> >
> > > Έστω πακέτο p και Α,B τα δύο άκρα μιας TCP σύνδεσης.
> > >
> > > Seq <sub>A</sub> <sup>p</sup>= Seq <sub>A</sub> <sup>p-1</sup> + Length <sub>A</sub> <sup>p-1</sup> <br></br>
>
> **_ACK Number_** _(Acknowledgement Number):_
>
> > Σε ένα πακέτο o αριθμός **_Ack_** δηλώνει την επιτυχή λήψη **n διαδοχικών** bytes.
> >
> > > Ack <sub>B</sub> <sup>p</sup>= Seq <sub>A</sub> <sup>p</sup> + Length <sub>A</sub> <sup>p</sup> <br></br>
