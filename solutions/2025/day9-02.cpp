#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

struct coords {
    ll x, y;
};

const bool DEB = true;
const int MAXM = 100005;

coords red_tiles[1005];
ll largest_area = 0, min_x = 1e12, min_y = 1e12, largest_x = 0, largest_y = 0;
int maxi;

// return if point with coords p is on the line segment formed by coords l1 and l2
bool on_line(coords p, coords l1, coords l2){
    return (p.x <= max(l1.x, l2.x) && p.x >= min(l1.x, l2.x) && p.y <= max(l1.y, l2.y) && p.y >= min(l1.y, l2.y));
}

bool lines_intersect(coords p1, coords p2, coords p3, coords p4){
    bool horizontal = false, vertical = false, horizontal2 = false, vertical2 = false;
    if(p1.x == p2.x) vertical = true;
    else if(p1.y == p2.y) horizontal = true;
    else cout<<"error, received invalid line segment!\n";

    if(p3.x == p4.x) vertical2 = true;
    else if(p3.y == p4.y) horizontal2 = true;
    else  cout<<"error, received invalid line segment!\n";

    if((horizontal && horizontal2) || (vertical && vertical2)){
        // should be false as it is allowed for p1 and p2 to be entirely on p3p4, but not the reverse!
        //if(on_line(p1, p3, p4) && on_line(p2, p3, p4)) return false; 
        if(on_line(p1, p3, p4)) return true;
        if(on_line(p2, p3, p4)) return true;
        if(on_line(p3, p1, p2)) return true;
        if(on_line(p4, p1, p2)) return true;
    }

    if(horizontal && vertical2){
        if(p1.y <= max(p3.y, p4.y) && p1.y >= min(p3.y, p4.y) && p3.x <= max(p1.x, p2.x) && p3.x >= min(p1.x, p2.x)){
            return true;
        }
    }

    if(vertical && horizontal2){
        if(p3.y <= max(p1.y, p2.y) && p3.y >= min(p1.y, p2.y) && p1.x <= max(p3.x, p4.x) && p1.x >= min(p3.x, p4.x)){
            return true;
        }
    }
    return false;
}

bool checkline(coords p1, coords p2){
    if(DEB) cout<<"\t checking line with points p1: "<<p1.x<<", "<<p1.y<<" p2: "<<p2.x<<", "<<p2.y<<"\n";
    for(int i = 0; i < maxi; i++){
        coords p3 = red_tiles[i];
        coords p4 = red_tiles[(i+1) % maxi];

        if(lines_intersect(p1, p2, p3, p4)){
            if(DEB) cout<<"\t Line intersected with p3: "<<p3.x<<", "<<p3.y<<" p4: "<<p4.x<<", "<<p4.y<<"\n";
            return false;
        }
    }
    return true;
}

bool checkpoint(coords point){
    if(DEB) cout<<"\t checking point "<<point.x<<", "<<point.y<<"\n";
    int intersections = 0;
    for(int i = 0; i < maxi; i++){
        coords p1 = red_tiles[i];
        coords p2 = red_tiles[(i+1) % maxi];
        // special case for when point is on the edge
        if(point.x == p1.x && p1.x == p2.x && point.y >= min(p1.y, p2.y) && point.y <= max(p1.y, p2.y)){
            return true;
        }
        if(point.y == p1.y && p1.y == p2.y && point.x >= min(p1.x, p2.x) && point.x <= max(p1.x, p2.x)){
            return true;
        }
        if(point.y > min(p1.y, p2.y) && point.y < max(p1.y, p2.y) && point.x <= max(p1.x, p2.x)){
            if(DEB) cout<<"\t \t point intersects with p1 "<<p1.x<<", "<<p1.y<<" p2 "<<p2.x<<", "<<p2.y<<"\n";
            //ll intersect = (point.y - p1.y) * (p2.x - p1.x) / (p2.y - p1.y) + p1.x;
            if(p1.x == p2.x){
                intersections++;
            }
        }
    }
    return intersections % 2 == 1;
}

void solve(){
    ll sum = 0;
    string input;

    int i = 0;

    int prevx = -1, prevy = -1;
    while(true){
        getline(cin, input, ',');
        if(input.empty()) break; // need to enter comma after pasting input
        ll ix = stoll(input);
        red_tiles[i].x = ix;
        getline(cin, input);
        ll iy = stoll(input);
        red_tiles[i].y = iy;
        i++;
    }
    maxi = i;
    for(i = 0; i < maxi; i++){
        for(int j=0; j< maxi; j++){
            ll new_area = (abs(red_tiles[i].x - red_tiles[j].x) + 1) * (abs(red_tiles[i].y - red_tiles[j].y) + 1);
            if(new_area > largest_area){
                ll ix = red_tiles[i].x, iy = red_tiles[i].y, jx = red_tiles[j].x, jy = red_tiles[j].y;
                coords p1, p2, p3, p4, p5, p6; // checking other 2 corners as well as four side midpoints
                coords p7; // also checking the middle point
                coords p8, p9, p10, p11; // also checking 4 points that reach a quarter distance
                p1.x = jx;
                p1.y = iy;
                p2.x = ix;
                p2.y = jy;

                p3.x = min(ix, jx) + abs(ix - jx) / 2;
                p3.y = min(iy, jy);
                p4.x = min(ix, jx) + abs(ix - jx) / 2;
                p4.y = max(iy, jy);

                p5.x = min(ix, jx); 
                p5.y = min(iy, jy) + abs(iy - jy) / 2;
                p6.x = max(ix, jx); 
                p6.y = min(iy, jy) + abs(iy - jy) / 2;

                p7.x = min(ix, jx) + abs(ix - jx) / 2;
                p7.y = min(iy, jy) + abs(iy - jy) / 2;

                p8.x = min(ix, jx) + abs(ix - jx) / 4;
                p8.y = min(iy, jy) + abs(iy - jy) / 4;

                p9.x = min(ix, jx) + abs(ix - jx) * 3 / 4;
                p9.y = min(iy, jy) + abs(iy - jy) / 4;

                p10.x = min(ix, jx) + abs(ix - jx) / 4;
                p10.y = min(iy, jy) + abs(iy - jy) * 3 / 4;

                p11.x = min(ix, jx) + abs(ix - jx) * 3 / 4;
                p11.y = min(iy, jy) + abs(iy - jy) * 3 / 4;

                if(DEB) cout<<"checking edges for i "<<ix<<", "<<iy<<" AND j "<<jx<<", "<<jy<<"\n";

                bool good_flag = true;
                coords sc;
                ll minx = min(ix, jx), miny = min(iy, jy), maxx = max(ix, jx), maxy = max(iy, jy), absx = max(abs(ix - jx) * 1 / 1000, 1LL), absy = max(abs(iy - jy) * 1 / 1000, 1LL);
                /*for(sc.x = minx, sc.y = miny; sc.x <= maxx && sc.y <= maxy; sc.x+=absx){
                    if(!checkpoint(sc)){
                        good_flag = false;
                        break;
                    }
                }
                if(good_flag) for(sc.x = minx, sc.y = maxy; sc.x <= maxx && sc.y <= maxy; sc.x+=absx){
                    if(!checkpoint(sc)){
                        good_flag = false;
                        break;
                    }
                }
                if(good_flag) for(sc.x = minx, sc.y = miny; sc.x <= maxx && sc.y <= maxy; sc.y+=absy){
                    if(!checkpoint(sc)){
                        good_flag = false;
                        break;
                    }
                }
                if(good_flag) for(sc.x = maxx, sc.y = miny; sc.x <= maxx && sc.y <= maxy; sc.y+=absy){
                    if(!checkpoint(sc)){
                        good_flag = false;
                        break;
                    }
                }*/
                coords corner1, corner2, corner3, corner4, corner5, corner6, corner7, corner8;
                corner1.x = minx + 1, corner1.y = miny + 1;
                corner2.x = minx + 1, corner2.y = maxy - 1;
                corner3.x = maxx - 1, corner3.y = miny + 1;
                corner4.x = maxx - 1, corner4.y = maxy - 1;

                corner5.x = minx + 1, corner5.y = maxy - 1;
                corner6.x = maxx, corner6.y = maxy;
                corner7.x = maxx, corner7.y = miny;
                corner8.x = maxx, corner8.y = maxy;
                if(checkline(corner1, corner2) && checkline(corner1, corner3) && checkline(corner2, corner4) && checkline(corner3, corner4)){
                    if(DEB) cout<<"new largest area found: "<<new_area<<"\n";
                    largest_area = new_area;
                }

                //if(checkpoint(p1) && checkpoint(p2) && checkpoint(p3) && checkpoint(p4) && checkpoint(p5) && checkpoint(p6) && checkpoint(p7)
                //  && checkpoint(p8) && checkpoint(p9) && checkpoint(p10) && checkpoint(p11) && good_flag){
                //}
            }
        }
    }
    cout<<largest_area;
}

int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(0)->sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    solve();

    return 0;
}
