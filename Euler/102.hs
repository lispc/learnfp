import qualified Data.List.Split as S
import qualified Data.String.Utils as U
import Prelude
contains::[Int]->Bool
contains p =
    (b1*b2>=0) && (b2*b3>=0) && (b1*b3>=0)
    where
    b1=(dcheck (p!!2) (p!!3) (p!!4) (p!!5))
    b2=(dcheck (p!!4) (p!!5) (p!!0) (p!!1))
    b3=(dcheck (p!!0) (p!!1) (p!!2) (p!!3))
    dcheck x1 y1 x2 y2=((-x2)*(y1-y2)-(x1-x2)*(-y2)) 
    --p=map read ps
main::IO()
main=do 
    content<-getContents
    let aa=map (S.splitOn ",") (lines content)
    mapM_ print $filter  contains (map (map read) aa)
