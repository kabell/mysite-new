N = int(input())
podmienky = []
def premenna(r,c): return N*r+c+1
def vypis_podmienku(p):
    for x in p: print(x,end=' ')
    print(0)
# v kazdom riadku je aspon jedna dama
for r in range(N): podmienky.append( [ premenna(r,c) for c in range(N) ] )
 # pomocna funkcia, vracia ci sa dve polıcka ohrozuju
def ohrozi(r1,c1,r2,c2): return r1==r2 or c1==c2 or r1+c1==r2+c2 or r1-c1==r2-c2
    # ziadne dve ohrozujuce sa polıcka nemaju naraz damu
for r1 in range(N):
    for c1 in range(N):
        for r2 in range(r1,N):
            for c2 in range(N):
                if (r1,c1)<(r2,c2) and ohrozi(r1,c1,r2,c2): podmienky.append( [-premenna(r1,c1),-premenna(r2,c2)] )
print('p cnf {} {}'.format(N**2,len(podmienky)+1))
for p in podmienky: vypis_podmienku(p)
print(str(premenna(47,47))+' 0')
