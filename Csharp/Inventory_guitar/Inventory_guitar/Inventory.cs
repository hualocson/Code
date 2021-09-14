using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace Inventory_guitar
{
    public class Inventory
    {
        private List<Guitar> guitars;

        public Inventory()
        {
            guitars = new List<Guitar>();
        }

        public Guitar getGuitar(string serialNumber)
        {
            foreach (var guitar in guitars)
            {
                if (guitar.getSerialNumber().Equals(serialNumber))
                    return guitar;
            }
            return null;
        }

        public Guitar search(Guitar searchGuitar)
        {
            foreach (var guitar in guitars)
            {
                string builder = searchGuitar.getBuilder();
                string model = searchGuitar.getModel();
                string type = searchGuitar.getType();
                string backWood = searchGuitar.getBackWood();
                string topWood = searchGuitar.getTopWood();

                if ((builder != null)
                    && (!builder.Equals(""))
                    && (!builder.Equals(guitar.getBuilder())))
                    continue;
                if ((model != null)
                     && (!model.Equals(""))
                     && (!model.Equals(guitar.getModel())))
                    continue;
                if ((type != null)
                    && (!searchGuitar.Equals(""))
                    && (!type.Equals(guitar.getType())))
                    continue;
                if ((backWood != null)
                    && (!backWood.Equals(""))
                    && (!backWood.Equals(guitar.getBackWood())))
                    continue;
                if ((topWood != null)
                    && (!topWood.Equals(""))
                    && (!topWood.Equals(guitar.getTopWood())))
                    continue;
            }
            return null;
        }

        public void addGuitar(string serialNumber,
                              double price,
                              string builder,
                              string model,
                              string type,
                              string backWood,
                              string topWood)
        {
            Guitar guitar = new Guitar(serialNumber,
                                       price,
                                       builder,
                                       model,
                                       type,
                                       backWood,
                                       topWood);
            guitars.Add(guitar);
        }
    }
}
